#include <bits/stdc++.h>
using namespace std;

class Matrix3x3{
    array<array<int, 3>, 3> matrix;
    public:
    Matrix3x3(){}
   Matrix3x3(array<int, 9> arr){
        for(int c = 0; c < 9; c++) {
            int row = c / 3;
            int col = c % 3;
            matrix.at(row).at(col) = arr.at(c);
        }
   }
   Matrix3x3(int a1, int a2, int a3,
              int a4, int a5, int a6,
              int a7, int a8, int a9)
        : matrix{{
            {a1, a2, a3},
            {a4, a5, a6},
            {a7, a8, a9}
        }}
    {}
   
    int getElement(int row, int col) const{
        if (row >= 3 | col >= 3) {
            cerr << "rad eli";
        }
        return matrix.at(row).at(col);
    }
    void setElement(int row, int col, int val){
        matrix.at(row).at(col) = val;
    }
    void transpose() {
        for(int i = 0; i  < 3; ++i) {
            for(int j = 0; j < i; ++j) {
                swap(matrix.at(i).at(j), matrix.at(j).at(i));
            }
        }
    }
    void print() {
        for (int i = 0; i < 3 ; ++i){
            for(int j = 0; j < 3;++j) {
                cout << matrix.at(i).at(j) << ' ';
            }
            cout << '\n';
        }
        cout << endl;
    }
};


int main() {
    
    //array<int, 9> arr = {1,2,3,4,5,6,7,8,9};
    Matrix3x3 matrix1(1,1,1,0,1,1,0,0,1);
    matrix1.print();
    matrix1.transpose();
    matrix1.print();
    i
    
    return 0;
}
