#include <iostream>
#include <vector>
#include <map>
#include <set>

std::vector<int> arrayRankTransform(const std::vector<int>& vec) {
	
	std::map<int,int> results;
	int i = 0;
	for(int x : vec) {
		results.insert(std::make_pair(x,0));
	}
	for(auto & x : results) {
		x.second = i;
		i++;
	}
	std::vector<int> ret;
	for(int x : vec) {
		ret.push_back(results[x]+1);
	}
	return ret;

}

int main () {
std::vector<int> arr = {40, 10, 20, 30};
auto result = arrayRankTransform(arr);
// result: {4, 1, 2, 3}
for(int x : result) { 
	std::cout << x << ' ';
} 
std :: cout << '\n';

std::vector<int> arr2 = {100, 100, 100};
auto result2 = arrayRankTransform(arr2);
// result2: {1, 1, 1}

for(int x : result2) {
	std::cout << x << ' ';
}
std::cout << '\n';


	


	return 0;
}
