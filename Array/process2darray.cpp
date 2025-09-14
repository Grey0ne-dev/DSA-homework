#include <bits/stdc++.h>
using namespace std;

template <typename T>
T pow2(T val) {
    return val * val;
}

template <typename T>
T inc(T val) {
    return ++val;
}

template<typename T, typename F, size_t Cols, size_t Rows>
array<array<T, Cols>, Rows> process2DArray(const array<array<T, Cols>, Rows>& source, F foo) {
    array<array<T, Cols>, Rows> res{};
    for (size_t i = 0; i < Rows; i++) {
        for (size_t j = 0; j < Cols; j++) {
            res[i][j] = foo(source[i][j]);
        }
    }
    return res;
}

template<typename T, size_t Cols, size_t Rows>
void print2DArray(const array<array<T, Cols>, Rows>& arr) {
    for (size_t i = 0; i < Rows; i++) {
        for (size_t j = 0; j < Cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    array<array<int, 3>, 3> matrix = {{
        {{1, 2, 3}},
        {{4, 5, 6}},
        {{7, 8, 9}}
    }};
    
    auto squared = process2DArray<int, decltype(pow2<int>), 3, 3>(matrix, pow2<int>);
    auto incremented = process2DArray<int, decltype(inc<int>), 3, 3>(matrix, inc<int>);
    
    cout << "Squared:\n";
    print2DArray(squared);

    cout << "\nIncremented:\n";
    print2DArray(incremented);
    
    return 0;
}
