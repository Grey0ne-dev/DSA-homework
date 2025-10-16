#include <deque>
#include <iostream>
#include <cmath>

template <typename T>
void rotateDeque(std::deque<T> &deq, int k) {
    int n = deq.size();
    if (n == 0) return;

    k %= n;

    if (k > 0) {
        for (int i = 0; i < k; ++i) {
            T val = deq.back();
            deq.pop_back();
            deq.push_front(val);
        }
    } else if (k < 0) {
        k = -k;
        for (int i = 0; i < k; ++i) {
            T val = deq.front();
            deq.pop_front();
            deq.push_back(val);
        }
    }
}

int main() {
    std::deque<int> d = {1, 2, 3, 4, 5};
    for (int x : d) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    
    rotateDeque(d, 2);
    for (int x : d) {
        std::cout << x << ' ';
        
    }
    std::cout << '\n';

    rotateDeque(d, -1);
    for (int x : d) {
        std::cout << x << ' ';
        
    }
    std::cout << '\n';
}
