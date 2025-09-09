#include <bits/stdc++.h>
using namespace std;


template <typename... Args>
int countArgs (Args... args) {
    return sizeof...(args);
}


int main() {
	
   cout << countArgs(6,4,0,9,7,8,6,0,2,7,3,4,6);
   
}