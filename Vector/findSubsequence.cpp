#include <bits/stdc++.h>
using namespace std;

   int findSubsequence(const vector<int>& seq, const vector<int>& sub) {
    int n = seq.size();
    int m = sub.size();

    for (int i = 0; i <= n - m; ++i) {
        bool match = true;
        for (int j = 0; j < m; ++j) {
            if (seq[i + j] != sub[j]) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }
    return -1;
}


int main() {
	vector <int> vec1 = {1, 1, 2, 3, 5, 8, };
	vector <int> vec2 = {1, 2};
	
	cout << findSubsequence(vec1, vec2);
return 0;
}
