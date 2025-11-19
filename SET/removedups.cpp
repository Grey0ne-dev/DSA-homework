#include <set>
#include <iostream>
#include <vector>

template <typename T>
std::vector<T> removedups(std::vector<T>& vec) {
    std::set<T> s(vec.begin(), vec.end());
    std::vector<T> res(s.begin(), s.end());
    return res;
}

template <typename C>
void print(const C& container) {
    for (auto i : container)
        std::cout << i << ' ';
    std::cout << '\n';
}

int main() {
    std::vector<int> v = {2, 4, 5, 5, 5, 21963};

    print(v); 
    v = removedups(v);
    print(v);
}

