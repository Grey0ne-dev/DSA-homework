#include <bits/stdc++.h>
using namespace std;

template<typename T, size_t N>
array<T,N> shiftArray(const array<T,N>& arr, int shift) {
    array<T, N> res;
    for (int i = 0; i < (int)arr.size(); i++) {
        int index = (i + shift) % (int)arr.size();
        if (index < 0) index += arr.size();
        res[i] = arr[index];
    }
    return res;
}

template<typename T, size_t N>
void print(const array<T,N>& arr) {
    for (auto& i : arr) cout << i << ", ";
    cout << '\n';
}

int main() {
    array<const char*, 9> arr = {
        "Creep",
        "Fake Plastic Trees",
        "Let Down",
        "Paranoid android",
        "My Iron Lung",
        "All I need",
        "Exit music",
        "Karma police",
        "No surprises"
    };
    
    auto shifted = shiftArray(arr, 3);
    print(shifted);
    
    return 0;
}
