#include <iostream>
#include <set>

int rangecount(std::set<int> st, int l, int h) {

	int count = 0;
	auto it1 = st.lower_bound(l);
	auto it2 = st.upper_bound(h);
	for(; it1 != it2; ++it1, count++);

	return count;
}

int main () {
	std::set<int> st = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int r = rangecount(st, 3, 7);
	std::cout << r << '\n';
	
	return 0;
}
