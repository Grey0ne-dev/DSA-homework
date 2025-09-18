#include <bits/stdc++.h>
using namespace std;


template <typename T, typename F>
vector<T> filterVector(vector<T> vec, F foo) {
    vector<T> res;
    size_t n = vec.size();
    for(int i = 0; i < n ; ++i ) {
        T dummie = vec[i];
        if(foo(dummie)) {res.push_back(dummie); }
    }
    return res;
}

bool isEven(int n) {return n & 1;}
bool is2pow(int n) {return !(n & (n-1));}
bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i');
}

template <typename T>
void print(vector<T> vec) {
    for(T x : vec) { cout << x << ' ';}
    cout << endl;
}


void Helloworld(const char * arg) {
        printf("%s", arg);
}

int main() {
	
	vector<int> nums= {1,2,3,4,5,6,7,8,9,16};
	vector<int> Twopows = filterVector(nums, is2pow);
	print(Twopows);
	Helloworld("printf");
	
return 0;
}
