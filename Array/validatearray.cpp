#include <bits/stdc++.h>
using namespace std;


template <typename T, size_t N, typename l>
bool validateArray(const array<T, N> & arr, l bottom, l top) {
    for(T i: arr){
        if(i < bottom || i > top) {return false;}
    }
    return true;
}


int main() {
    
    array<float, 4> floats= {3.14, 2.1368, 0.74 , 0};
    
    cout << boolalpha << validateArray(floats, INT_MIN, INT_MAX);
    
    return 0;
}