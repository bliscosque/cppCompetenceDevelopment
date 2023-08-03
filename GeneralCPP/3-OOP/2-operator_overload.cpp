#include <iostream>
#include <vector>

using namespace std;

class Matrix {

private:
    vector<vector<int>> m;
    int lines, columns;
public:
    Matrix(vector<vector<int>> vvi) {
        m=vvi;
        lines=vvi.size();
        columns=vvi[0].size();
    }

    //overload of +
    Matrix operator+(Matrix const& other) {
        vector<vector<int>> ans_m (lines,vector<int>(columns,0));
        auto cur_m=m;
        auto other_m=other.m;
        for (int i=0;i<lines;i++) {
            for (int j=0;j<columns;j++) {
                ans_m[i][j]=m[i][j]+other_m[i][j];
            }
        }
        Matrix ans(ans_m);
        return ans;
    }
    void print() {
        auto cur_m=m;
        for (int i=0;i<lines;i++) {
            for (int j=0;j<columns;j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    Matrix m1=Matrix({{1,2,3},{4,5,6}});
    Matrix m2=Matrix({{6,5,4},{3,2,1}});
    Matrix m3=m1+m2;
    m3.print();
    
    return 0;
}