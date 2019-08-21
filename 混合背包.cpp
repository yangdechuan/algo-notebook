/*
有 N 种物品和一个容量是 V 的背包。

物品一共有三类：

第一类物品只能用1次（01背包）；
第二类物品可以用无限次（完全背包）；
第三类物品最多只能用 si 次（多重背包）；
每种体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
*/
#include <algorithm>
#include <cstdio>
using namespace std;

// 有 N 种物品和一个容量是 V 的背包
int N, V;
// 第 i 种物品最多有 s[i] 件，每件体积是 v[i]，价值是 w[i]。
int v[10000], w[10000], s[10000];
// dp[j] 表示背包容量不超过j的最大价值
int dp[1000 + 1];

int main() {
    // 输入并将多重背包转化为01背包
    scanf("%d%d", &N, &V);
    int total = 0;
    for (int i = 0; i < N; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (z == -1) {
            v[total] = x;
            w[total] = y;
            s[total] = 1;
            total++;
        } else if (z == 0) {
            v[total] = x;
            w[total] = y;
            s[total] = 0;
            total++;
        } else {
            for (int k = 1; k < z; k <<= 1) {
                v[total] = k * x;
                w[total] = k * y;
                s[total] = 1;
                z -= k;
                total++;
            }
            if (z) {
                v[total] = z * x;
                w[total] = z * y;
                s[total] = 1;
                total++;
            }
        }
    }
    // 同时解01背包和完全背包
    for (int j = 0; j <= V; j++) dp[j] = 0;
    for (int i = 0; i < total; i++) {
        if (s[i] == 1) {
            // 01背包
            for (int j = V; j >= v[i]; j--) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        } else {
            // 完全背包
            for (int j = v[i]; j <= V; j++) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }
    printf("%d", dp[V]);

    return 0;
}

/*
参考：https://www.acwing.com/problem/content/7/
样例输入:
4 5
1 2 -1
2 4 1
3 4 0
4 5 2

样例输出：
8
*/