#include <bits/stdc++.h>
using namespace std;

template <size_t N>
std::array<int, 256> countFrequency(const std::array<char, N>& text) {
    std::array<int, 256> res{};
    
    #ifndef __GNUC__
    res.fill(0);
    #endif
    
    size_t i = 0;
    while (i < N && text[i] != '\n') {
        unsigned char c = static_cast<unsigned char>(text[i]);
        res[c]++;
        i++;
    }

    return res;
}


int main() {
    
    std::array<char, 5> text = {'h', 'e', 'l', 'l', 'o'};
    auto freq = countFrequency<5>(text);
    for (size_t i = 0; i < freq.size(); ++i) {
        std::cout << (char)i << ": " <<freq[i] << "\n";
    }
    cout << endl;
    
    return 0;
}