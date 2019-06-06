/*
有N个重量和价值分别为wi和vi的物品，从这些物品中挑选出不超过W的物品，使得总价值最大。
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 4000;
int N, W;
int w[MAXN], v[MAXN];

// 当背包容量不大时候，针对不同的重量限制计算最大的价值。
// 时间：O(NW) 空间:O(NW)
int solve1() {
    // dp[i][j]表示考虑前i个物品在不超过j容量的最大价值。
    // 因为0个物品没有价值，所以显然d[0][j]=0。
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {               // 如果容量j装不下物品i
                dp[i][j] = dp[i - 1][j];  // 不装
            } else {                      // 如果容量j装得下物品i
                dp[i][j] = max(dp[i - 1][j],
                               dp[i - 1][j - w[i]] + v[i]);  // 装还是不装
            }
        }
    }
    return dp[N][W];
}
// 时间：O(NW) 空间：O(W)
int solve2() {
    vector<int> dp(W + 1, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return dp[W];
}

// 如果n和vi很小，但是W和wi很大，针对不同的价值计算最小的重量。
// 时间：O(NV) 空间：O(NV)
const int MAXV = 100;
int solve3() {
    // dp[i][j]表示前i个物品挑选出价值总和为j时的最小重量。
    vector<vector<int>> dp(N + 1, vector<int>(N * MAXV + 1));
    dp[0][0] = 0;
    for (int j = 1; j <= N * MAXV; j++) dp[0][j] = 0x3f3f3f;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N * MAXV; j++) {
            if (j < v[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    for (int j = N * MAXV; j >= 0; j--) {
        if (dp[N][j] <= W) return j;
    }
}
// 时间：O(NV) 空间：O(V)
int solve4() {
    vector<int> dp(N * MAXV + 1);
    dp[0] = 0;
    for (int j = 1; j <= N * MAXV; j++) dp[j] = 0x3f3f3f;
    for (int i = 1; i <= N; i++) {
        for (int j = N * MAXV; j >= v[i]; j--) {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    for (int j = N * MAXV; j >= 0; j--) {
        if (dp[j] <= W) return j;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &N, &W);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }
    int ans = solve4();
    printf("%d", ans);
    return 0;
}
/*
参考：OpenJudge 4131：Charm Bracelet
样例输入:
4 6
1 4
2 6
3 12
2 7
样例输出：
23
*/