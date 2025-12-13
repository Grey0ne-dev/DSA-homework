#include <iostream>
#include <vector>
#include <queue>


int k_lowest(std::vector<int>& array, int k) {
	
	std::priority_queue<int, std::vector<int>, std::greater<int>> q(array.begin(), array.end());
	
	for(int i = 0 ;i < k-1 ; i++ ) {
		q.pop();
	}
	
	return q.top();

}


int main () {
	
	std::vector<int> nums = {7, 10, 4, 3, 20, 15, -1, 8};
int k = 3;
std::cout << k_lowest(nums, k) << '\n';


}
