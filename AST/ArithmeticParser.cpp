#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

enum class TokenType {
    NUMBER,
    OPERATION,
    LEFT_PAREN,
    RIGHT_PAREN,
    VARIABLE
};

struct Token {
    TokenType type;
    std::string value;
    Token(TokenType t, const std::string& v) : type(t), value(v) {}
};

class Lexer {
    std::vector<Token> tokens;
    const std::string operators = "+-*/%";
    
    bool is_operator(char c) {
        return operators.find(c) != std::string::npos;
    }
    
public:
    Lexer(const std::string& expression) {
        for (size_t i = 0; i < expression.length(); i++) {
            char c = expression[i];
            
            if (std::isspace(c)) continue;
            
            if (std::isdigit(c)) {
                std::string result;
                while (i < expression.length() && std::isdigit(expression[i])) {
                    result += expression[i++];
                }
                i--;
                tokens.emplace_back(TokenType::NUMBER, result);
            }
            else if (std::isalpha(c)) {
                tokens.emplace_back(TokenType::VARIABLE, std::string(1, c));
            }
            else if (c == '(') {
                tokens.emplace_back(TokenType::LEFT_PAREN, "(");
            }
            else if (c == ')') {
                tokens.emplace_back(TokenType::RIGHT_PAREN, ")");
            }
            else if (is_operator(c)) {
                tokens.emplace_back(TokenType::OPERATION, std::string(1, c));
            }
        }
    }
    
    std::vector<Token> get_tokens() const {
        return tokens;
    }
};

class Parser {
private:
    std::vector<Token> tokens;
    size_t pos;
    
    class AST_Node {
    public:
        virtual ~AST_Node() = default;
        virtual double evaluate(double x = 0, double y = 0, double z = 0) = 0;
        virtual std::string to_string() = 0;
    };
    
    class NumberNode : public AST_Node {
        double data;
    public:
        NumberNode(double val) : data(val) {}
        double evaluate(double, double, double) override { return data; }
        std::string to_string() override { return std::to_string((int)data); }
    };
    
    class VariableNode : public AST_Node {
        char name;
    public:
        VariableNode(char n) : name(n) {}
        double evaluate(double x, double y, double z) override {
            switch (name) {
                case 'x': return x;
                case 'y': return y;
                case 'z': return z;
                default: throw std::runtime_error("Unknown variable");
            }
        }
        std::string to_string() override { return std::string(1, name); }
    };
    
    class OperationNode : public AST_Node {
        char op;
        AST_Node* left;
        AST_Node* right;
    public:
        OperationNode(char operation, AST_Node* l, AST_Node* r)
            : op(operation), left(l), right(r) {}
        ~OperationNode() override { delete left; delete right; }
        
        double evaluate(double x, double y, double z) override {
            double L = left->evaluate(x, y, z);
            double R = right->evaluate(x, y, z);
            switch (op) {
                case '+': return L + R;
                case '-': return L - R;
                case '*': return L * R;
                case '/': if (R == 0) throw std::runtime_error("Division by zero");
                          return L / R;
                case '%': if ((int)R == 0) throw std::runtime_error("Modulo by zero");
                          return (int)L % (int)R;
                default: throw std::runtime_error("Unknown operator");
            }
        }
        std::string to_string() override {
            return "(" + left->to_string() + " " + op + " " + right->to_string() + ")";
        }
    };
    
    Token& current_token() { return tokens[pos]; }
    
    AST_Node* parse_primary() {
        if (current_token().type == TokenType::NUMBER) {
            double value = std::stod(current_token().value);
            pos++;
            return new NumberNode(value);
        }
        else if (current_token().type == TokenType::VARIABLE) {
            char name = current_token().value[0];
            pos++;
            return new VariableNode(name);
        }
        else if (current_token().type == TokenType::LEFT_PAREN) {
            pos++;
            AST_Node* node = parse_expression();
            if (current_token().type != TokenType::RIGHT_PAREN)
                throw std::runtime_error("Expected ')'");
            pos++;
            return node;
        }
        throw std::runtime_error("Unexpected token");
    }
    
    int get_precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/' || op == '%') return 2;
        return 0;
    }
    
    AST_Node* parse_expression(int min_prec = 0) {
        AST_Node* left = parse_primary();
        while (pos < tokens.size() && tokens[pos].type == TokenType::OPERATION) {
            char op = tokens[pos].value[0];
            int prec = get_precedence(op);
            if (prec < min_prec) break;
            pos++;
            AST_Node* right = parse_expression(prec + 1);
            left = new OperationNode(op, left, right);
        }
        return left;
    }
    
public:
    Parser(const std::vector<Token>& t) : tokens(t), pos(0) {}
    
    AST_Node* build() {
        if (tokens.empty()) return nullptr;
        return parse_expression();
    }
};

int main() {
    std::cout << "Expression Evaluator with Variables (x, y, z) and Modulo\n";
    std::cout << "Supported operators: + - * / %\n";
    std::cout << "Enter expression (or 'quit' to exit)\n\n";

    std::string expression;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, expression);
        if (expression == "quit") break;
        
        try {
            Lexer lex(expression);
            Parser parser(lex.get_tokens());
            auto* tree = parser.build();
            
            double x, y, z;
            std::cout << "Enter x y z: ";
            std::cin >> x >> y >> z;
            std::cin.ignore();
            
            std::cout << "AST: " << tree->to_string() << "\n";
            std::cout << "Result: " << tree->evaluate(x, y, z) << "\n";
            delete tree;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}

