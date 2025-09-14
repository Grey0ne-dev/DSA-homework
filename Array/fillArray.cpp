#include <bits/stdc++.h>
using namespace std;


array<int,7> createArray() {
    array<int, 7> arr= {1, 2, 3, 4, 5, 6, 7};
    return arr;
}

void print(array<int, 7> arr) {
    for(int i : arr) {
        cout << i << ' ';
    }
    cout << endl;
}

void modify(array<int, 7> & arr, int n) {
    for(int & i : arr) {
        i = n;
    }
    
}

int main() {
	
    array<int, 7> my_array = createArray();
    print(my_array);
    modify(my_array, 7);
    print(my_array);
}