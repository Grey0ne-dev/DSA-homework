#include <bits/stdc++.h>
using namespace std;


    string reverse(string s) {
        stack<char> st;
        string res;
        for(char c : s) {
            st.push(c);
        }
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    } 
    
int main() {
	
	string str = "hiDsemaJnorbeL";
    cout << reverse(str);
    
    return 0;
}
