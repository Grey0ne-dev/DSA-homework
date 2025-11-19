#include <vector>
#include <set>
#include <stdexcept>
#include <cmath>
#include <iostream>


int removeRange(std::set<int>& s, int lbound, int ubound) {
    int count = 0;
    
    auto it = s.lower_bound(lbound);
    
    while (it != s.end() && *it <= ubound) {
        it = s.erase(it);
        count++;
    }
    
    return count;
}


int main() {
    
    std::set s = {1, 3, 5, 7, 9, 11, 13, 15};
int removed = removeRange(s, 5, 11);
std::cout << removed << '\n';  // 4
// s теперь содержит: {1, 3, 13, 15}

    return 0;
}
