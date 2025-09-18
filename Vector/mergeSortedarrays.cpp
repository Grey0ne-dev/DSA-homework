#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<int> mergeSortedVectors(const std::vector<int> &first, const std::vector<int> &second) {
    
    int i = 0;
    int j = 0;
    int l = 0;
    int k = first.size() + second.size();
    std::vector<int> res(k);
    while(i < first.size() && j < second.size()) {
        if(first[i] < second[j]) {
            res[l] = first[i];
            l++;
            i++;
        } else {
            res[l] = second[j];
            j++;
            l++;
        }
    }
    
    while(i < first.size()){
        res[l] = first[i];
        i++;
        l++;
    }
    
     while(j < second.size()){
        res[l] = second[j];
        j++;
        l++;
    }
    
    return res;
}

int main() {
    
    std::vector<int> vec = {1,1,5,5,5,7,8};
    std::vector<int> nig = {78,96,100,555};
    std::vector<int> res = mergeSortedVectors(vec, nig);
    for(int x : res) { std::cout << x << ' ';}
    
    return 0;
}