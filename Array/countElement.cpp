#include <bits/stdc++.h>
using namespace std;



template <typename F>
int countElements(array<int, 7> &arr, F foo){
    int count = 0;
    for(int & i : arr) {
        if(foo(i)) {count++;}
    }
    return count;
}

bool isZero(int n) {
    return !(bool)(n);
}

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
	
    array<int, 7> arr = {1, 3, 54, 76, 86, 33, 65};
    cout << "Count of zeros: " << countElements(arr, isZero) << '\n';
    cout << "Count of 2pows: " << countElements(arr, isPowerOfTwo) << '\n';
    return 0;
}