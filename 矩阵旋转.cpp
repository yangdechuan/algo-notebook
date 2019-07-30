/*
不分配另外一个矩阵的情况下，将一个矩阵顺时针旋转90度。
 */
#include<vector>

using namespace std;


// 法一：
// 将矩阵分成“左上”、“右上”、“右下”、“左下”四部分
// 矩阵旋转就是：“左上”==“右上”==>“右下”==>“左下”==>“左上”
// （i, j）==> (j, n-1-i) ==> (n-1-i, n-1-j) ==> (n-1-j, i) ==> (i, j)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int maxx = n / 2;
        int maxy = (n + 1) / 2;
        for(int i = 0; i < maxx; i++) {
            for(int j = 0; j < maxy; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};

// 法二：
// 先以左上-右下对角条线为轴做翻转
// 再以中心的竖线为轴做翻转；
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i ++ )
            for (int j = i + 1; j < n; j ++ )
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < n; i ++ )
            for (int j = 0, k = n - 1;
                    j < k; j ++, k -- )
                swap(matrix[i][j], matrix[i][k]);
    }
};