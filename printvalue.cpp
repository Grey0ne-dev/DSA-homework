#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printValue(T arg) {
    cout << arg;
}


template <>
void printValue<bool>(bool arg) {
    cout << boolalpha << arg;
}


template <>
void printValue<char>(char arg) {
    cout << "'" << arg << "'";
}

int main() {
    printValue(42);
    cout << "\n";
    
    printValue(false);
    cout << "\n";
    
    printValue('A');
    cout << "\n";

    return 0;
}
