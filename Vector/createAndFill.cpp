#include <iostream>
#include <vector>


std::vector<int> createAndFillVector(int n) {
    std::vector<int> vec(n);
    for(int i = 0; i < n;++i ){
        vec[i] = i;
    }
    return vec;
}


int main () {
    
    
    std::vector<int> vec = createAndFillVector(12);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    
    
    return 0;
}