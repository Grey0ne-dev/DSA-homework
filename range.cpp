#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Range {
    T f, t;
public:
    Range(T from, T to) {
        if (from <= to) {
            this->f = from;
            this->t = to;
        } else {
            throw invalid_argument("Range: from must be <= to");
        }
    }

    bool contains(T arg) const {
        return (f <= arg && arg <= t);
    }

    T length() const {
        return (int)t - (int)f;
    }

    void print() const {
        for (T i = f; i < t; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }
};


int main () {
    
    Range<char> a('a', 'f');
    //Range<int> (0, -5) exception
    Range<int> b(0, 12);
    
    cout << b.length();
    a.print();
    
    
    return 0;
}