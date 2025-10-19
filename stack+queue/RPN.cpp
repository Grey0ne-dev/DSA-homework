#include <iostream>
#include <stack>
#include <vector>

std::string evaluateRPN(std::vector<std::string>& expr) {
    std::stack<std::string> st;
    for(const std::string& s : expr) {
        if(!(s == "+" || s == "-" || s == "/" || s == "*")) {
            st.push(s);
            continue;
        }
        double x = std::stoi(st.top());
        st.pop();
        double y = std::stoi(st.top());
        switch(s[0]) {
            case '+': y += x; break;
            case '-': y -= x; break;
            case '*': y *= x; break;
            case '/': 
                if(y != 0) {
                    y /= x;
                }
                break;
            default: 
                throw std::invalid_argument("Invalid operator!\n");
        }
        st.pop();
        st.push(std::to_string(y));
    }
    return st.top();
}

int main() {
    std::vector<std::string> expr = {"5", "3", "+", "12",  "4",  "/",  "*", "7",  "2", "-", "-"};
    std::cout << evaluateRPN(expr) << '\n';
    return 0;
}