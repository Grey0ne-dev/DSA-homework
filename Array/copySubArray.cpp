#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t N, size_t M>
array<T, M> copySubArray(const array<T, N>& source, int startIndex, size_t size) {
    if (startIndex < 0 || startIndex >= N || size > N - startIndex || size > M) {
        throw std::out_of_range("Invalid startIndex or size");
    }
    array<T, M> res;
    for (size_t i = 0; i < size; i++) {
        res.at(i) = source.at(i + startIndex);
    }
    return res;
}

template <typename T, size_t N>
void print(const array<T, N>& arr) {
    for (const T& i : arr) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    array<const char*, 8> arr = {
        "nmap", "Harvester", "Maltego", "BurpSuite", "Ghidra", "nikto", "Ettercap", "Wireshark"
    };
    array<const char*, 2> brr = copySubArray<const char*, 8, 2>(arr, 3, 2);
    print(brr);
    return 0;
}