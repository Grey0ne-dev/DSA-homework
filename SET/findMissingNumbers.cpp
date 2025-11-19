#include <bits/stdc++.h>

#include <vector>
#include <set>

std::vector<int> findMissingNumbers(const std::set<int>& numbers) {
    std::vector<int> res;

    if (numbers.size() < 2) return res;

    auto it = numbers.begin();
    auto next_it = std::next(it);

    for (; next_it != numbers.end(); ++it, ++next_it) {
        int diff = *next_it - *it;

        for (int val = *it + 1; val < *next_it; ++val) {
            res.push_back(val);
        }
    }

    return res;
}


int main() {
	
	std::set<int> st;
	st.insert(1000);
	st.insert(20);
	std::vector<int> vec = findMissingNumbers(st);
	for(int i : vec) {
	    std::cout << i << ' ';
	}

}
