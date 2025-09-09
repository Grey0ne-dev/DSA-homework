#include <bits/stdc++.h>
using namespace std;


//template <typename T, typename... Args>
auto sum () {
    return 0;
}


template <typename T, typename... Args>
auto sum (T first, Args... args) {
    return first + sum(args...);
}


int main() {
	
    cout << sum(9,7,2,3) << '\n';
    cout << sum (92346, 93.824, 49071.23, 78.34) << '\n';
}
