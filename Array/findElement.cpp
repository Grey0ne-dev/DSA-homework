#include <bits/stdc++.h>
using namespace std;


template <typename T, size_t N>
int findElement(const array<T, N>& arr, T element) {
    for(size_t i = 0; i < arr.size(); ++i) {
        if(arr[i] == element) {return i;}
    }
    return -1;
}


int main() {
	
	
	array <const char*, 3> arr = {"Brave", "new", "world"};
	
	cout << "Index of world is: " << findElement(arr, "world") << endl;
    cout << "Index of hello is: " << findElement(arr, "Hello") << endl;
    
    return 0;
}