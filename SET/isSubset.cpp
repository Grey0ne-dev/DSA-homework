#include <set>
#include <vector>
#include <iostream>


bool isSubset(std::vector<int> v1, std::vector<int> v2) {

	std::set<int> st;
	for(int i : v1) {
		st.insert(i);
	}
	
	size_t s = st.size();
	for(int i : v2) {
		st.insert(i);
	}
	return v2.size() == st.size();
}

int main () {
	
std::vector v = {1,2,3,4,5,6,7};
std::vector v2 = {1,2,3,4,5,6,7};
std::cout << std::boolalpha << isSubset(v,v2);	

}
