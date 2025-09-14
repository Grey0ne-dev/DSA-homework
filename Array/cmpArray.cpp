#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t N>
bool cmpArray(array<T, N> & arr, array<T, N> & brr) {
    size_t n = arr.size();
    for(int i = 0; i < n; i++) {
        if(arr[i] != brr[i]) {return false;}
    }
    return true;
    
}


int main() {
	
	array<int, 2> arr = {1, 2};
	array<int, 2> brr = {1, 2};
    
    cout << ((cmpArray(arr, brr))? "yes" : "no");
    
    return 0;
}