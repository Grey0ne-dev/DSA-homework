#include <bits/stdc++.h>
using namespace std;


array<int,5> createArray() {
    array<int, 5> arr= {1, 2, 3, 4, 5};
    return arr;
}

void print(array<int, 5> arr) {
    for(int i : arr) {
        cout << i << ' ';
    }
    cout << endl;
}
int main() {
	
    print(createArray());

}
