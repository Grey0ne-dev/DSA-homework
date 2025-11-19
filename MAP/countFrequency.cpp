#include <iostream>
#include <map>
#include <vector>

std::map<int, int> countFrequency(std::vector<int> v) {
	std::map<int, int> freqs;
	for(auto c : v) {
		freqs[c]++;
	}
	return freqs;
}


int main () {
	
std::vector<int> v = {1,2,3,4,5,6, 6, 6};

std::map<int, int> freqs = countFrequency(v);

for(auto p : freqs) {
	std::cout << p.first << ' ' << p.second << '\n';
}
}
