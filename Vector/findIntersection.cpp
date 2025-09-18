#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> findIntersection(const vector<int>& a, const vector<int>& b) {
    set<int> setA(a.begin(), a.end());
    set<int> setB(b.begin(), b.end());
    vector<int> result;

    for (int val : setA) {
        if (setB.count(val)) {
            result.push_back(val);
        }
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {3, 4, 5, 6};
    vector<int> inter = findIntersection(a, b);

    for (int val : inter) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
