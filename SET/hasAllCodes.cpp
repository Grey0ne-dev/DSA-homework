#include <vector>
#include <set>
#include <stdexcept>
#include <cmath>
#include <iostream>

bool hasAllCodes(const std::string &s, int k) {
    if (s.size() < std::pow(2, k)) {
        return false;
    }
    std::string result;
    std::set<std::string> st;
    for (int i = 0; i < s.size() - k; i++) {
        result = s.substr(i, k);
        st.insert(result);
    }
    return st.size() == std::pow(2, k);
}



int main() {
    
    
    std::cout << hasAllCodes("00110110", 2) << '\n';

    std::cout << hasAllCodes("0110", 1) << '\n';

    std::cout << hasAllCodes("0110", 2) << '\n';

    std::cout << hasAllCodes("0000000001011100", 4) << '\n';


    return 0;
}
