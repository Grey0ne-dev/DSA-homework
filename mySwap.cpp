#include <bits/stdc++.h>
using namespace std;


template<typename G>



void mySwap(G & first, G & sec){
    G temp = first;
    first = sec;
    sec = temp;
}



int main() {
	
	std::string str = "nigga", str2 = "niggers";
	int x = 69, y = 96;
	double z = 1.0978, j = 9832;
	
    mySwap(str, str2);
    mySwap(x, y);
    mySwap(z, j);
    
}
