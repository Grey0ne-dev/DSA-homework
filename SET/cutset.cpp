#include <iostream>
#include <vector>
#include <set>

template <typename T>
	std::vector cutset(const std::vector<T>& v1,const std::vector<T>& v2){
	
	std::set<T> st;
	std::vector<t> res;
	for(auto i : v1) {
		st.insert(i);
	}
	size_t size = st.size();
	for(auto i : v2) {
		st.insert(i);
		if(st.size() != size) {size = st.size.();}
		else {
			res.push_back(i);
		}
	}
	return res;
}

int main() {

	std::vector<int> set1 = {1, 2, 3, 4, 5};
	std::vector<int> set2 = {2, 3, 4, 5};
	std::vector<int> cut = cut(set1, set2);
	for(auto i : cut) {
		std::cout << i <<'\n';
	}
	return 0;
}

