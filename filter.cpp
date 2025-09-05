#include <bits/stdc++.h>
using namespace std;


template<typename G>

bool isEven(const G & a){
    G temp = a;
    return (a % 2 == 0);
}

template<typename G,typename F>
std::vector<G> filterArray (G * arr, int size, F func) {
    
    std::vector<G> res;
    for(int i = 0; i < size ; i++) {
        if(func(arr[i])) {
            res.push_back(arr[i]);
        }
    }
    return res;
}

int main() {
	
    int cars[4] = {8, 6,  4, 5};
    vector<int> vec = filterArray(cars, 4, isEven<int>);
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec.at(i) << ' ';
    }
    
}


