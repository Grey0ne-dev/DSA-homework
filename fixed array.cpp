#include <bits/stdc++.h>
using namespace std;

template <typename T>

class FixedArray {
    
    T* arr;
    size_t n;
    
    public:
    FixedArray (T * arr, size_t n) : n(n), arr(new T[n]){
        for(int i = 0; i < n; i++){
            this->arr[i] = arr[i];
        }
    }
    void set(size_t index, T element) {
        arr[index] = element;
    }
    T& get(size_t index) const {return arr[index];}
    size_t size() {return n;}
};




int main() {
	
	int n[4] = {0, 3, 5, 4};
	string s[2] = {"Hello", "World"};
	
    FixedArray<int> nums(n, 4);
    FixedArray<string> strings(s, 2);
    
    cout << nums.get(2) << '\n';
    nums.set(2, 2);
    cout << nums.get(2) << '\n';
    
    cout << strings.get(0) << " " << strings.get(1) << "!" <<'\n';
    
    return 0;
}
