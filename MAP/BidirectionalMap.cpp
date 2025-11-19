#include <iostream>
#include <map>
#include <string>

class BidirectionalMap {
    std::map<int, std::string> fwd;
    std::map<std::string, int> bwd;

public:

    void insert(int key, const std::string & value) {
        fwd[key] = value;
        bwd[value] = key;
    }

    std::string getByKey(int key) const {
        auto it = fwd.find(key);
        if (it != fwd.end())
            return it->second;

        return "";
    }

    int getByValue(const std::string& value) const {
        auto it = bwd.find(value);
        if (it != bwd.end())
            return it->second;

        return -1;
    }

    void deleteByKey(int key) {
        auto it = fwd.find(key);
        if (it == fwd.end()) return;

        bwd.erase(it->second);
        fwd.erase(it);
    }

    void deleteByValue(const std::string& value) {
        auto it = bwd.find(value);
        if (it == bwd.end()) return;

        fwd.erase(it->second);
        bwd.erase(it);
    }
};

int main() {
    return 0;
}

