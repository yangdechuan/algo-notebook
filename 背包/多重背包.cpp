/*
有 N 种物品和一个容量是 V 的背包。

第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
*/
#include <algorithm>
#include <cstdio>

using namespace std;

// 有 N 种物品和一个容量是 V 的背包
int N, V;
// 第 i 种物品最多有 s[i] 件，每件体积是 v[i]，价值是 w[i]。
int v[1000 + 1], w[1000 + 1], s[1000 + 1];
// dp[j] 表示背包容量不超过j的最大价值
int dp[20000 + 1];

/*
朴素多重背包，如果S很大会超时。
时间复杂性：O(N*V*S)
*/
int main() {
    scanf("%d%d", &N, &V);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d", &v[i], &w[i], &s[i]);
    }
    for (int i = 0; i <= V; i++) dp[i] = 0;
    // DP
    for (int i = 1; i <= N; i++) {
        for (int j = V; j >= v[i]; j--) {  // 根01背包类似，从后往前计算。
            int K = min(j / v[i], s[i]);
            for (int k = 1; k <= K; k++) {
                dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
            }
        }
    }
    printf("%d", dp[V]);

    return 0;
}

/*
二进制优化的多重背包，将多重背包问题转化为01背包问题。
时间复杂性：O(N*V*logS)
*/
int vv[20000], ww[20000];
int main2() {
    // 输入
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &N, &V);
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d", &v[i], &w[i], &s[i]);
    }
    // 转为01背包
    int total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= s[i]; j <<= 1) {
            vv[total] = j * v[i];
            ww[total] = j * w[i];
            total++;
            s[i] -= j;
        }
        if (s[i] != 0) {
            vv[total] = s[i] * v[i];
            ww[total] = s[i] * w[i];
            total++;
        }
    }
    // 求解01背包
    for (int i = 0; i <= V; i++) dp[i] = 0;
    for (int i = 0; i < total; i++) {
        for (int j = V; j >= vv[i]; j--) {
            dp[j] = max(dp[j], dp[j - vv[i]] + ww[i]);
        }
    }
    printf("%d", dp[V]);

    return 0;
}

/*
参考：https://www.acwing.com/problem/content/5/
样例输入:
4 5
1 2 3
2 4 1
3 4 3
4 5 2

样例输出：
10
*/