#include <vector>
#include <set>
#include <stdexcept>
#include <cmath>
#include <iostream>

std::vector<int> symetricCut(const std::vector<int>& a, const std::vector<int>& b) {
    std::set<int> s(a.begin(), a.end());
    for (int x : b)
        if (!s.erase(x))
            s.insert(x);
    return {s.begin(), s.end()};
}



int main() {
    
    std::vector<int> a= {1,2,3,4};
    std::vector<int> b= {3,4,5,6,7};
    std::vector<int> c = symetricCut(a,b);
    for(int x : c) {
        std::cout << x << ' ';
    }

    return 0;
}
