#include <map>
#include <string>
#include <iostream>

std::map<std::string, int> mergeMaps(std::map<std::string,int> f, std::map<std::string, int> s) {

	std::map<std::string, int> m; 
	for(std::pair x : f) { 
		m.insert(x); 
	} 
	for(auto x : s) { 
		m[x.first] += x.second; 
	}
	return m;
}

int main() { 

	std::map<std::string, int> map1 = {{"a", 1}, {"b", 2}, {"c", 3}};
std::map<std::string, int> map2 = {{"b", 3}, {"c", 4}, {"d", 5}};
auto result = mergeMaps(map1, map2);
// result: {{"a", 1}, {"b", 5}, {"c", 7}, {"d", 5}}
	
for(auto x : result) {
	std::cout << x.first << ' ' << x.second << '\n'; 
}
	return 0;
}

