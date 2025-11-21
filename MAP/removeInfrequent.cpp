#include <iostream>
#include <map>

int removeInfrequent(std::map<std::string, int>& mp, int i) {
    int removed = 0;
    auto it = mp.begin();
    
    while (it != mp.end()) {
        if (it->second < i) {
            it = mp.erase(it);
            removed++;
        } else {
            ++it;
        }
    }
    
    return removed;
}


int main() {
	
	std::map<std::string, int> freq = {{"apple", 5}, {"banana", 2}, {"cherry", 8}, {"date", 1}};
	int removed = removeInfrequent(freq, 3);
	std::cout << removed << '\n';  // 2
	// freq теперь содержит: {{"apple", 5}, {"cherry", 8}}
	
}
