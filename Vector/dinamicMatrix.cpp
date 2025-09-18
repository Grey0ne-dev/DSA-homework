#include <iostream>
#include <vector>
using namespace std;

class DynamicMatrix {
private:
    vector<vector<int>> data;

public:
    DynamicMatrix(int rows, int cols) {
        data.resize(rows, vector<int>(cols, 0));
    }

    int getElement(int row, int col) const {
        if (row < 0 || row >= data.size() || col < 0 || col >= data[0].size()) {
            throw out_of_range("Index out of range");
        }
        return data[row][col];
    }

    void setElement(int row, int col, int value) {
        if (row < 0 || row >= data.size() || col < 0 || col >= data[0].size()) {
            throw out_of_range("Index out of range");
        }
        data[row][col] = value;
    }

    void addRow() {
        if (data.empty()) return;
        data.push_back(vector<int>(data[0].size(), 0));
    }

    void addColumn() {
        for (auto& row : data) {
            row.push_back(0);
        }
    }

    void print() const {
        for (const auto& row : data) {
            for (const auto& val : row) {
                cout << val << "\t";
            }
            cout << "\n";
        }
    }
};

int main() {
    DynamicMatrix matrix(3, 3);
    matrix.setElement(1, 1, 42);
    matrix.addRow();
    matrix.addColumn();
    matrix.print();
    return 0;
}
