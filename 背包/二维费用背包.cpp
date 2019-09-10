/*
有 N 件物品和一个容量是 V 的背包，背包能承受的最大重量是 M。

每件物品只能用一次。体积是 vi，重量是 mi，价值是 wi。

求解将哪些物品装入背包，可使物品总体积不超过背包容量，总重量不超过背包可承受的最大重量，且价值总和最大。
*/
#include <algorithm>
#include <cstdio>
using namespace std;

int N, V, M;
int v[1000 + 1], m[1000 + 1], w[1000 + 1];
int dp[100 + 1][100 + 1];

int main() {
    scanf("%d%d%d", &N, &V, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d", &v[i], &m[i], &w[i]);
    }
    for (int j = 0; j <= V; j++) {
        for (int k = 0; k <= M; k++) {
            dp[j][k] = 0;
        }
    }
    // 类似01背包，从后往前计算。
    for (int i = 1; i <= N; i++) {
        for (int j = V; j >= v[i]; j--) {
            for (int k = M; k >= m[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - v[i]][k - m[i]] + w[i]);
            }
        }
    }
    printf("%d", dp[V][M]);

    return 0;
}

/*
参考：https://www.acwing.com/problem/content/8/
样例输入:
4 5 6
1 2 3
2 4 4
3 4 5
4 5 6

样例输出：
8
*/