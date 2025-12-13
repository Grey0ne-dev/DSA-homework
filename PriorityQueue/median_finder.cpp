#include <iostream>
#include <queue>

class MedianFinder {
    std::priority_queue<int> max;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min;
    
    void balance() {
        if (max.size() > min.size() + 1) {
            min.push(max.top());
            max.pop();
        } else if (min.size() > max.size() + 1) {
            max.push(min.top());
            min.pop();
        }
    }
    
public:
    MedianFinder() = default;
    
    void addNum(int num) {
        if (max.empty() || num <= max.top()) {
            max.push(num);
        } else {
            min.push(num);
        }
        
        balance();
        
        if (!max.empty() && !min.empty() && max.top() > min.top()) {
            int maxTop = max.top();
            int minTop = min.top();
            max.pop();
            min.pop();
            
            max.push(minTop);
            min.push(maxTop);
        }
    }
    
    float findMedian() {
        if (max.size() == min.size()) {
            return (max.top() + min.top()) / 2.0;
        } else if (max.size() > min.size()) {
            return max.top();
        } else {
            return min.top();
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    std::cout << mf.findMedian() << '\n';  // 1.5
    mf.addNum(3);
    std::cout << mf.findMedian() << '\n';  // 2.0
    
    MedianFinder mf2;
    mf2.addNum(5);
    mf2.addNum(1);
    mf2.addNum(3);
    mf2.addNum(4);
    mf2.addNum(2);
    std::cout << mf2.findMedian() << '\n';  // 3.0
    
    return 0;
}
