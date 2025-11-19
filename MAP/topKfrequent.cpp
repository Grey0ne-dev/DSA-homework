#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {

    std::map<int, int> mp;
    for (int x : nums) {
        mp[x]++;
    }
    std::vector<std::pair<int,int>> temp;
    temp.reserve(mp.size());
    for (auto& p : mp) {
        temp.push_back(p);
    }
    std::sort(temp.begin(), temp.end(),
              [](auto& a, auto& b) {
                  return a.second > b.second;
              });

    std::vector<int> res;
    res.reserve(k);
    for (int i = 0; i < k && i < (int)temp.size(); i++) {
        res.push_back(temp[i].first);
    }

    return res;
}



int main () {

	std::vector<int> nums = {1, 1, 1, 2, 2, 3};
auto result = topKFrequent(nums, 2);
// result: {1, 2}
	for(auto x : result) {
		std::cout << x << ' ';
	}

return 0;
}
