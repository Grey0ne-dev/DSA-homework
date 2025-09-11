#include <iostream>
#include <utility>
#include <string>
#include <cmath>
using namespace std;

template<typename T>
void print(T& arg) {
    cout << arg << "[Lvalue]\n";
}

template<typename T>
void print(T&& arg) {
    cout << arg << "[Rvalue]\n";
}

void betterPrint() {}

template<typename T, typename... Args>
void betterPrint(T&& arg, Args&&... args) {
    print(forward<T>(arg));
    betterPrint(forward<Args>(args)...);
}

int main() {
    int x = 5;
    string s = "nigger";
    const string cs = "const nigger";
    
    betterPrint(1, x, s, cs, "literally nigger", pow(2, 8-9+5));
    
    return 0;
}