#include <iostream>
#include <map>
#include <string>

int firstUnic(std::string & str) {
	std::map<char,int> mp;

	for(char c : str) {
		mp[c]++;
	}
	for(int i = 0; str[i];i++ ) {
		if (mp[str[i]] == 1) return i;
	}
	return -1;
}

int main () {
	
	std::string s = "leetcode";
	std::cout << firstUnic(s) << '\n';  // 0 ('l')

	std::string s2 = "loveleetcode";
	std::cout << firstUnic(s2) << '\n';  // 2 ('v')


	return 0;
} 
