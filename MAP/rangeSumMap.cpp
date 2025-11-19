#include <iostream>
#include <map>

int rangeSumMap(std::map<int,int> mp, int l, int u ) {

	int sum = 0;
	for(int i = l; i <= u ; i++ ) {
		sum += mp[i];
	}
	return sum;
}

int main () {
	
	std::map<int, int> m = {{1, 10}, {3, 20}, {5, 30}, {7, 40}};
	std::cout << rangeSumMap(m, 3, 7) << '\n';  // 90 (20 + 30 + 40)
	std::cout << rangeSumMap(m, 2, 4) << '\n';  // 20 (только ключ 3)
	
	return 0;
}
