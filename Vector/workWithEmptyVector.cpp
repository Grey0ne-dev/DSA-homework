#include <iostream>
#include <vector>
#include <stdexcept>


void workWithEmptyVector(std::vector<int> &vec) {
    
    if(vec.capacity() != 0) {
        //throw std::runtime_error("NOT EMPTY VECTOR DATA WILL BE ERASED\n"); 
        std::cerr<< " WARNING!! NON EMPTY VECTOR. DATA WILL BE ERASED\n";
    }
    
    for(int i = 0; i <= 10 ; ++i) {
        vec.push_back(i);
        std::cout << i << ".th iteration of loop\n";
        std::cout << "size: " << vec.size() << "\n";
        std::cout << "capacity " << vec.capacity() << "\n" << std::endl;
    }
    
} 

int main () {
    
    std::vector<int> vec;
    std::vector<int> vec2(10);
    workWithEmptyVector(vec);
    
    return 0;
}