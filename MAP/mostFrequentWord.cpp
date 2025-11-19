#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

std::string mostFrequentWord(const std::string & stream) {
    std::string ops = ";:.,?/'-+!";
    std::map<std::string, int> freqs;
    
    std::string currentWord;
    
    for (size_t i = 0; i <= stream.length(); i++) {
        if (i == stream.length() || stream[i] == ' ') {
            if (!currentWord.empty()) {
                std::transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);
                freqs[currentWord]++;
                currentWord.clear();
            }
        } else {
            char c = stream[i];
            if (ops.find(c) == std::string::npos) {
                currentWord += c;
            }
        }
    }
    
    std::string mostFrequent;
    int maxCount = 0;
    
    for (const auto& pair : freqs) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequent = pair.first;
        }
    }
    
    return mostFrequent;
}

int main() {
    std::string text = "Bob hit a ball, the Hit BALL flew far after it was HIT.";
    std::cout << mostFrequentWord(text) << '\n';
    
    std::string text2 = "hello world hello";
    std::cout << mostFrequentWord(text2) << '\n';
    
    return 0;
}
