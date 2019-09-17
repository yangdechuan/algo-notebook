#include <iostream>
#include <vector>
using namespace std;

// 稀疏矩阵每一项
class MatrixTerm {
   public:
    int row, col;  // 元素所在行和列（从1开始编号）
    int val;
};

// 稀疏矩阵
class SparseMatrix {
   public:
    int rows, cols;            // 矩阵行数、列数
    vector<MatrixTerm> terms;  // 非0项表
};

// 重载矩阵输入输出流
istream& operator>>(istream& in, SparseMatrix& x) {
    int numberOfTerms;
    cout << "Enter number of rows, columns, and #terms" << endl;
    in >> x.rows >> x.cols >> numberOfTerms;
    x.terms.resize(numberOfTerms);
    MatrixTerm term;
    for (int i = 0; i < numberOfTerms; i++) {
        cout << "Enter row, columns, and value of term " << i + 1 << endl;
        in >> term.row >> term.col >> term.val;
        x.terms[i] = term;
    }
    return in;
}
ostream& operator<<(ostream& out, SparseMatrix& x) {
    out << "rows = " << x.rows << "columns = " << x.cols << endl;
    for (auto it = x.terms.begin(); it != x.terms.end(); it++) {
        out << "a(" << it->row << "," << it->col << ") = " << it->val << endl;
    }
    return out;
}

// 矩阵乘
// A * B ==> C
void matmul(SparseMatrix& A, SparseMatrix& B, SparseMatrix& C) {
    C.rows = A.rows;
    C.cols = B.cols;
    vector<vector<int>> res(C.rows + 1, vector<int>(C.cols + 1, 0));
    for (auto ia = A.terms.begin(); ia != A.terms.end(); ia++) {
        for (auto ib = B.terms.begin(); ib != B.terms.end(); ib++) {
            int ra = ia->row;
            int ca = ia->col;
            int rb = ib->row;
            int cb = ib->col;
            if (ca == rb) {
                res[ra][cb] += (ia->val * ib->val);
            }
        }
    }
    MatrixTerm term;
    for (int i = 1; i <= C.rows; i++) {
        for (int j = 1; j <= C.cols; j++) {
            if (res[i][j] != 0) {
                term.row = i;
                term.col = j;
                term.val = res[i][j];
                C.terms.push_back(term);
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    SparseMatrix A, B, C;
    cin >> A >> B;
    matmul(A, B, C);
    cout << C;

    return 0;
}
