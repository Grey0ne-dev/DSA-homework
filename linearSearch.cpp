#include <bits/stdc++.h>
using namespace std;

template <typename T>
    
int linearSerach(std::vector<T> vec, T element) {
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] == element) {return i;}
    }
    return -1;
}



int main() {
	
    vector<int> integers = {1,2,3,4,5,6,7};
    vector<double> constants = {3.14159, 2.71828, 1.61803, 0.91596, 0.69314};
    vector<string> cpu_s = {"Ryzen", "Threadripper", "Xeon", "Celeron"};
    
    cout << "Index of number 5: " << linearSerach<int>(integers, 5) << '\n';
    cout << "Index of golden ratio: " << linearSerach<double>(constants, 1.61803) << '\n';
    cout << "Index of Pentium: " << linearSerach<string>(cpu_s, "Pentium");
    return 0;
}
