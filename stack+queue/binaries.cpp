#include <bits/stdc++.h>
using namespace std;

vector<string> generateBinary(int n) {
    vector<string> binaries;
    if(n) {
        queue<string> q;
        q.push("1");
        for (int i = 0; i < n; i++) {
            string curr = q.front();
            binaries.push_back(curr);
            q.pop();
            q.push(curr + "0");
            q.push(curr + "1");
        }
    }
    return binaries;
}


int main() {
	vector<string> b =generateBinary(20);
	for(auto num: b) {
	    cout << num << '\n';
	}
}