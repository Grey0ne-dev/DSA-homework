#include <iostream>
#include <vector>
#include <stdexcept>

void manageCapacity(std::vector<int> & vec) {
    int s1 = vec.size();
    int c1 = vec.capacity();
    
    std::cout << "size раньше: " << s1 << '\n';
    std::cout << "capacity раньше: " << c1 << '\n';
    vec.reserve(500);
    int c2 = vec.capacity();
    for(int i = s1; i < c2 ; ++i ) {
        vec.push_back(i);
    }
    int s2 = vec.size();
    std::cout << "дiкий size: " << s2 << '\n';
    std::cout << "дикiй capacity: " << c2 << '\n';
    
}


int main () {
    
    std::vector<int> vec(8,4);
    manageCapacity(vec);
    std::cout <<"дикий огурец" << std::endl;
    
    return 0;
}