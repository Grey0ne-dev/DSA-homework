#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct Point {
    int x = 0;
    int y = 0;
};

struct cmp {
    bool operator()(const Point& a, const Point& b) const {
        return a.x * 1LL * a.x + a.y * 1LL * a.y >
               b.x * 1LL * b.x + b.y * 1LL * b.y;
    }
};

std::vector<Point> k_closest(const std::vector<Point>& points, int k) {
    std::vector<Point> res;

    k = std::min(k, (int)points.size());

    std::priority_queue<Point, std::vector<Point>, cmp> pq(points.begin(), points.end());

    for (int i = 0; i < k; i++) {
        res.push_back(pq.top());
        pq.pop();
    }

    return res;
}

int main() {
    std::vector<Point> pts = {{1, 3}, {-2, 2}, {5, 8}};
auto result = k_closest(pts, 2);
// result: {{-2, 2}, {1, 3}}
// Расстояния: (-2)²+(2)² = 8, (1)²+(3)² = 10, (5)²+(8)² = 89

    for (auto& p : result) {
        std::cout << p.x << " " << p.y << "\n";
    }
}

