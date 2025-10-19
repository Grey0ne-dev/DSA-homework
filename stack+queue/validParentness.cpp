#include <bits/stdc++.h>
using namespace std;


bool isValid(string s) {
        stack <char>buf;
    for(char x : s) {
        if      ( x == '[') {buf.push('[');}
        else if (x == '{') {buf.push('{');}
        else if (x == '(') {buf.push('(');}
        else if (x == '<') {buf.push('<');}
        else if (x == '}') {
            if(buf.top() != '{') {return false;}
            buf.pop();
        }
        else if (x == ']') {
            if(buf.empty() ||buf.top() != '[') {return false;}
            buf.pop();
        }
        else if (x == ')') {
            if(buf.empty() || buf.top() != '(') {return false;}
            buf.pop();
        }
        else if (x == '>') {
            if(buf.empty() || buf.top() != '<') {return false;}
            buf.pop();
        }
    }
    return buf.empty();
    }

int main() {
	
	
	

}
