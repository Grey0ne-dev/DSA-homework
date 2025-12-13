#include <iostream>
#include <set>
using namespace std;

int main() {

ios::sync_with_stdio(false);
cin.tie(nullptr);

    long long x, n;
    cin >> x >> n;

    set<long long> lights;
    multiset<long long> lengths;

    lights.insert(0);
    lights.insert(x);
    lengths.insert(x);

    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;

        auto it = lights.lower_bound(p);
        long long right = *it;
        long long left = *prev(it);
        
        lengths.erase(lengths.find(right - left));
        lengths.insert(p - left);
        lengths.insert(right - p);

        
        lights.insert(p);
        cout << *lengths.rbegin() << " ";
    }

    return 0;
}
