#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

class VectorStats {
private:
    vector<double> data;

public:
    VectorStats(const vector<double>& vec) : data(vec) {}

    void addValue(double value) {
        data.push_back(value);
    }

    void removeValue(double value) {
        auto it = find(data.begin(), data.end(), value);
        if (it != data.end()) {
            data.erase(it);
        }
    }

    double mean() const {
        if (data.empty()) throw runtime_error("Empty vector");
        double sum = 0.0;
        for (double val : data) sum += val;
        return sum / data.size();
    }
    
    double median() const {
        if (data.empty()) throw runtime_error("Empty vector");
        vector<double> temp = data;
        sort(temp.begin(), temp.end());
        size_t n = temp.size();
        if (n % 2 == 1) {
            return temp[n / 2];
        } else {
            return (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
        }
    }

    void print() const {
        for (double val : data) cout << val << " ";
        cout << endl;
    }
};

int main() {
    VectorStats stats({1.0, 2.0, 3.0, 4.0});
    cout << "Mean: " << stats.mean() << endl;
    cout << "Median: " << stats.median() << endl;

    stats.addValue(5.0);
    stats.removeValue(2.0);

    cout << "After changes:" << endl;
    cout << "Mean: " << stats.mean() << endl;
    cout << "Median: " << stats.median() << endl;

    stats.print();
    return 0;
}
