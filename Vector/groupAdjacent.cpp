#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> groupAdjacent( vector<int>& vec) {
    vector<vector<int>> res;
    if (vec.empty()) return res;

    res.push_back(vector<int>());
    int border = vec.size() - 1;
    int i = 0;
    int j = 0;

    while (i <= border) {
        res[j].push_back(vec[i]);
        if (vec[i] != vec[++i]) {
            if (i <= border) res.push_back(vector<int>());
            ++j;
        }
    }

    return res;
}

template <typename T>
void print(T x) {
    cout << x << ' ';
}

template<typename T>
void print(vector<T> vec) {
    cout << '(';
    for(T x : vec) {
        print(x);
    }
    cout << ") \n";
}


int main() {
	
	vector<int> vec1= {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9};
	vector<vector<int>> vec2 = groupAdjacent(vec1); 
	print(vec2);
return 0;
}
