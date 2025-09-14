#include <bits/stdc++.h>
using namespace std;


template <typename T>
void swapp(T & el1, T & el2) {
    T temp = el1;
    el1 = el2;
    el2 = temp;
}


template <typename T, size_t N>
void reverseArray(array<T, N> & arr) {
    size_t n = arr.size() / 2;
    size_t m = arr.size() - 1;
    for(size_t i = 0; i < n; ++i) {
        swapp(arr.at(i), arr.at(m - i));
    }
}


template <typename T, size_t N>
void print(const array <T, N> & arr) {
    for(T i : arr) {
        cout << i << ' ';
    }
    cout << endl;
}


int main() {
	
	
	array <const char*, 3> arr = {"trust", "but", "verify"};
	print(arr);
	reverseArray(arr);
	print(arr);
    
    array<char, 7> brr = {'A','L','U','C','U','R','D'};
	reverseArray(brr);
	print(brr);
    
    return 0;
}