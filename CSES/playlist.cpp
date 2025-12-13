#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int longestSubsequenceLength(std::vector<int>& vec) {
    std::set<int> st;
    int maxLen = 0;
    int left = 0;
    int sz = vec.size(); 
    for(int right = 0; right < sz; right++) {
        while(st.count(vec[right])) {
            st.erase(vec[left]);
            left++;
        }
        
        st.insert(vec[right]);
        maxLen = std::max(maxLen, (int)st.size());
    }
    
    return maxLen;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> args(n);
    for(int i = 0; i < n; i++) {
        std::cin >> args[i];
    }
    std::cout << longestSubsequenceLength(args); 
}

int main() {
    solve();
}
