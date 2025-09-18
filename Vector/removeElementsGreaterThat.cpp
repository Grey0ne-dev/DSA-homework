#include <iostream>
#include <vector>
#include <stdexcept>


bool isSorted(std::vector<int> vec) {
    int n = vec.size();
    for(int i = 0; i < n-1; ++i) {
        if(vec[i] > vec[i+1]) {return false;}
    }
    return true;
}

int removeElementsGreaterThan(std::vector<int> vec, int g) {
    
    if(!isSorted(vec)) {
        throw std::invalid_argument("vector isnt sorted");
    }
    int n = vec.size();
    int n1 = 0;
    for(int i = n-1; i >=0 ; --i ){
        if(vec[i] > g) {
            vec.erase(vec.begin() + i);
            n1++;
        } 
    }
    return n1;
}

int main () {
    
    std::vector<int> vec(8,4);
    std::cout << removeElementsGreaterThan(vec, 2);
    
    return 0;
}