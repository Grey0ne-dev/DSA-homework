#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<char, std::vector<std::string>> groupByFirstChar(std::vector<std::string> vec) {

	std::map<char, std::vector<std::string>> result;

	for(auto str : vec) {
		result[str[0]].push_back(str);
	} 

	return result;
}

int main() {
	
	std::vector<std::string> strings= {
		"nigger",
		"auto",
		"jewelry",
		"robber",
		"jackass"
	};
	
	std::map<char, std::vector<std::string>> group = groupByFirstChar(strings);

	for(auto p : group) {
		std::cout << p.first << ": ";
		for(std::string str : p.second) {
			std::cout << str << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}
