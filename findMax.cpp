#include <bits/stdc++.h>
using namespace std;


template <typename T>
auto findMax (T first) {
    return first;
}


template <typename T, typename... Args>
auto findMax (T first, Args... args) {
    return max(first, findMax(args...));
}


int main() {
	
   cout << findMax(873,46589,73265,973,24,65);
   
}
