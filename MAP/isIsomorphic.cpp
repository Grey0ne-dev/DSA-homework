#include <string>
#include <iostream>
#include <map>
#include <set>

bool isIsomorphic(const std::string& str1, const std::string& str2) {
	
if(str1.size() != str2.size()) {return false;}
	std::map<char, char> fwd;
    std::map<char, char> bwd;

    for (size_t i = 0; str1[i]; i++) {
        char a = str1[i];
        char b = str2[i];

        if (!fwd.count(a) && !bwd.count(b)) {
            fwd[a] = b;
            bwd[b] = a;
        }
        else {
            if (fwd[a] != b) return false;
            if (bwd[b] != a) return false;
        }
    }

    return true;	
}


int main() {

std::cout << isIsomorphic("egg", "ddd") << '\n';     // 1 (true)
std::cout << isIsomorphic("foo", "bar") << '\n';     // 0 (false)
std::cout << isIsomorphic("paper", "title") << '\n'; // 1 (true)
						     //
}
