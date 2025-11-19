#include <vector>
#include <set>
#include <stdexcept>
#include <cmath>
#include <iostream>

int findClosest(const std::set<int>& st, int target) {
    if (st.empty()) 
        throw std::invalid_argument("set is empty");

    auto it = st.lower_bound(target);

    if (it == st.end()) 
        return *std::prev(it);

    if (it == st.begin()) 
        return *it;

    auto prev_it = std::prev(it);
    if (std::abs(*it - target) < std::abs(*prev_it - target))
        return *it;
    else
        return *prev_it;
}


int main() {
    std::set<int> nums = {1, 4, 7, 10, 15, 20};

    int targets[] = {0, 3, 8, 10, 13, 22};
    for (int t : targets) {
        try {
            int closest = findClosest(nums, t);
            std::cout << "Target: " << t 
                      << " → Closest: " << closest << '\n';
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << '\n';
        }
    }

    return 0;
}
