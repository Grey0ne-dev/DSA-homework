#include <bits/stdc++.h>
using namespace std;


template<typename G>


G sumArray(G* arr, int size){
    G res = *(arr);
    for(int i = 1; i < size; i++){
        res += arr[i];
    }
    return res;
    
}


int main() {
	
    std::string cars[4] = {"Maibach", "Lamborgini", "BMW", "Porshe"};
    std::string str1 = sumArray(cars, 4);
    std::cout << str1;
}


