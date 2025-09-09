#include <iostream>
#include <string>

using namespace std;

template <typename... Args>
string makeSentance(string first, Args... args) {
    if constexpr (sizeof...(args) > 0) {
        return first + " " + makeSentance(args...);
    } else {
        return first + ".";
    }
}

int main() {
    cout << makeSentance("nill", "kiggers");
    cout << endl;
    return 0;
}