#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool cmpValue(T arg1, T arg2) {
    return arg1 == arg2;
}


template <>
bool cmpValue<char *>(char* arg1, char* arg2) {
    return (bool)strcmp(arg1, arg2) == 0;
}



int main() {
    
    char * str1 = "nigger";
    char * str2 = "nigger";
    char * str3 = str2;
    
    int i = 9;
    int j = 2;
    
    cout << (cmpValue(str1,str2) ? "true \n" : "false \n");
    cout << (cmpValue(str2, str3) ? "true \n" : "false \n");
    cout << (cmpValue(i, j) ? "true\n" : "false\n");

    
    

    return 0;
}
