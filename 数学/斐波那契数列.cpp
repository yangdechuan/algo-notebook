#include <iostream>
#include <vector>
using namespace std;

/*
时间复杂度：O(n)
dp(n) = dp(n - 1) + dp(n - 2)
*/
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int x = 0, y = 1;
    for (int i = 2; i <= n; i++) {
        int tmp = x + y;
        x = y;
        y = tmp;
    }
    return y;
}

/*
快速幂方法
时间复杂度：O(logn)
f(n+1) = 1 1 * f(n)
f(n)     1 0   f(n-1)
*/
typedef vector<vector<int>> mat;
mat mul(mat& A, mat& B) {
    mat C = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    return C;
}
mat pown(mat A, int n) {
    mat B = {{1, 0}, {0, 1}};
    while (n) {
        if (n & 1) {
            B = mul(B, A);
        }

        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int fibonacci2(int n) {
    mat A = {{1, 1}, {1, 0}};
    A = pown(A, n);
    return A[1][0];
}

int main() {
    for (int i = 0; i < 10; i++) cout << fibonacci(i) << endl;
    return 0;
}