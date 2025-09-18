#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
void resizeVector(std::vector<T>& vec, size_t newSize, T defaultVar) {
    size_t oldSize = vec.size();
    vec.resize(newSize, defaultVar);
}

int main() {
    std::vector<int> numbers = {1, 2, 3};
    
    std::cout << "Before resize: ";
    for (auto n : numbers) std::cout << n << " ";
    std::cout << "\n";

    resizeVector(numbers, 6, 42);

    std::cout << "After resize (expanded): ";
    for (auto n : numbers) std::cout << n << " ";
    std::cout << "\n";

    resizeVector(numbers, 2, 0);

    std::cout << "After resize (shrunk): ";
    for (auto n : numbers) std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
