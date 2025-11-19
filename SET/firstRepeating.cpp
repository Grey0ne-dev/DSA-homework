#include <vector>
#include <set>
#include <stdexcept>
#include <cmath>
#include <iostream>


int firstRepeating(const std::vector<int>& v) {
    std::set<int> seen;
    for (int x : v) {
        if (!seen.insert(x).second) {
            return x;
        }
    }
    return -1;
}



int main() {
    
std::vector<int> nums = {1, 2, 3, 4, 2, 5, 6, 3};
std::cout << firstRepeating(nums) << '\n';  // 2

    return 0;
}
