#include <iostream>
using namespace std;

template <typename T>
T x2 (T arg){
    return arg * 2;
}

template <typename T>
T sq (T arg) {
    return arg * arg;
}

template <typename F, typename... Args>
void applyAndPrint(F foo, Args... args) {
    // gitem vor fold expression chenk ancel
    ((cout << foo(args) << '\n'), ...);
}

int main() {
    applyAndPrint(x2<int>, 2, 4, 5, 985);
}
