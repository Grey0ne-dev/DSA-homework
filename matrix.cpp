#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Matrix {
    T** arr;
    int rows;
    int columns;

public:
    Matrix(int r, int c) : rows(r), columns(c) {
        arr = new T*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new T[columns];
            for (int j = 0; j < columns; j++) {
                arr[i][j] = 0; // initialize with 0
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) delete[] arr[i];
        delete[] arr;
    }

    int getRowsCount() const { return rows; }
    int getColumnsCount() const { return columns; }

    void set(int i, int j, T element) {
        arr[i][j] = element;
    }

    T get(int i, int j) const { return arr[i][j]; }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            throw invalid_argument("Matrix dimensions do not match!");
        }
        Matrix res(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                res.set(i, j, this->get(i, j) + other.get(i, j));
            }
        }
        return res;
    }
};


int main() {
    // 2x2 matrices
    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);

    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);

    B.set(0, 0, 5);
    B.set(0, 1, 6);
    B.set(1, 0, 7);
    B.set(1, 1, 8);

    cout << "Matrix A:\n";
    A.print();

    cout << "Matrix B:\n";
    B.print();

    Matrix<int> C = A + B;
    cout << "Matrix A + B:\n";
    C.print();

    Matrix<double> D(3, 3);
    Matrix<double> E(3, 3);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            D.set(i, j, i + j * 0.1);
            E.set(i, j, (i+1) + (j+1) * 0.1);
        }
    }

    cout << "Matrix D:\n";
    D.print();
    cout << "Matrix E:\n";
    E.print();

    Matrix<double> F = D + E;
    cout << "Matrix D + E:\n";
    F.print();

    return 0;
}

