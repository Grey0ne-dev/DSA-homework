#include <iostream>
#include <queue>
#include <vector>

std::vector<int> mergeKSorted(const std::vector<std::vector<int>>& lists) {
    using It = std::vector<int>::const_iterator;

    struct Node {
        It it;
        It end;
        bool operator>(const Node& other) const {
            return *it > *other.it;
        }
    };

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    std::vector<int> res;

    for (const auto& lst : lists) {
        if (!lst.empty()) {
            pq.push(Node{lst.begin(), lst.end()});
        }
    }

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        res.push_back(*cur.it);

        ++cur.it;
        if (cur.it != cur.end) {
            pq.push(cur);
        }
    }

    return res;
}

int main() {
    std::vector<std::vector<int>> lists = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };
    
    auto result = mergeKSorted(lists);
    
    for (int x : result) std::cout << x << " ";
    // Output: 1 1 2 3 4 4 5 6
}

