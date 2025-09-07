#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>

class Pair {
    T1 first;
    T2 second;
    public:
    Pair(T1 first, T2 second) : first(first), second(second) {}
    const T1 getFirst() {return first;}
    const T2 getSecond() {return second;}
    void setFirst(const T1 & arg) {first = arg;}
    void setSecond(const T2 & arg) {second = arg;}
    const void print() {cout << first << ':' << second << endl;}
};




int main() {
	
    Pair <double, double> coords (2, 2.87);
    Pair  <string, short> codename ("flowers", 21);
    Pair <char, int> model ('e', 320);
    coords.print();
    codename.print();
    model.print();
    return 0;
}
