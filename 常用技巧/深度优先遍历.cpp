/*
参考：OpenJudge 1088：滑雪
样例输入:
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

样例输出：
25
*/
#include <algorithm>
#include <cstdio>

using namespace std;

int R, C;         // 行数和列数
int H[100][100];  // 高度
int dp[100][100];  // dp[i][j]表示从(i,j)开始最长的滑坡，-1表示还没有计算

// 四个方向
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 深度优先遍历递归实现
int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < R && yy >= 0 && yy < C && H[xx][yy] < H[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(xx, yy) + 1);
        }
    }
    return dp[x][y];
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &H[i][j]);
            dp[i][j] = -1;
        }
    }
    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (dp[i][j] == -1) {
                ans = max(ans, dfs(i, j));
            }
        }
    }
    printf("%d", ans);
    return 0;
}