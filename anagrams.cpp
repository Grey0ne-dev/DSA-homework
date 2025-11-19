#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& vec) {
    std::vector<std::string> vecTmp = vec;
    for (auto& el : vec) {
        std::sort(el.begin(), el.end());
    }
    std::map<std::string, std::vector<std::string>> mp;
    for (int i = 0; i < vec.size(); i++) {
        mp[vec[i]].push_back(vecTmp[i]);
    }

    std::vector<std::vector<std::string>> result;
    for (auto el : mp) {
        result.push_back(el.second);
    }
    return  result;
}

int main() {
    std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = groupAnagrams(words);
    for (const auto& el : result) {
        for (const std::string& sec : el) {
            std::cout << sec << " ";
        }
        std::cout << std::endl;
    }

}

