#include <bits/stdc++.h>
using namespace std;

template <typename T>
auto makePairLists(T last) {
    return last;
}

template <typename T, typename... Args>
auto makePairLists(T first, Args... rest) {
    return make_pair(first, makePairLists(rest...));
}

void printPair(char c) {
    if (isalpha(c)) {
        cout << "'" << c << "'";
    } else {
        cout << c;
    }
}

void printPair(int i) {
    cout << i;
}

template <typename T1, typename T2>
void printPair(const pair<T1, T2>& p) {
    cout << "{";
    printPair(p.first);
    cout << " ";
    printPair(p.second);
    cout << "}";
}

int main() {
    auto p = makePairLists(4, 3, 9, 8, 7, 1, '2', 8, 'a', 'r', 'f', 'h', 'b');
    printPair(p);
    cout << endl;
    return 0;
}