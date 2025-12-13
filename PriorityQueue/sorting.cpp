#include <iostream>
#include <queue>
#include <vector>

void sort(std::vector<int>& arr) {
	std::priority_queue<int, std::vector<int>, std::greater<int>> q(arr.begin(), arr.end());

	arr.clear();
	while(!q.empty()){
		arr.push_back(q.top());
		q.pop();
	}
	
}

void print(std::vector<int>& v) {
	for(int x : v) {
	std::cout << x << ' ';
	}
	std::cout << '\n';
}


int main() {
	
	std::vector<int> nums = {12,344,65,6,3};
	sort(nums);
	print(nums);

	return 0;
}
