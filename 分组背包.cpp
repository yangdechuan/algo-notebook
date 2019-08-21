/*
有 N 组物品和一个容量是 V 的背包。

每组物品有若干个，同一组内的物品最多只能选一个。
每件物品的体积是 vij，价值是 wij，其中 i 是组号，j 是组内编号。

求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。
*/

#include <algorithm>
#include <cstdio>
using namespace std;

int N, V;
int v[100], w[100];
int dp[100 + 1];

int main() {
    scanf("%d%d", &N, &V);
    for (int j = 0; j <= V; j++) dp[j] = 0;
    // 类似01背包，从后往前计算
    // dp(i, j) = max{ dp(i-1, j), max{ dp(i-1, j-vik) + wik } }
    for (int i = 0; i < N; i++) {
        int s;
        scanf("%d", &s);
        for (int k = 0; k < s; k++) {
            scanf("%d%d", &v[k], &w[k]);
        }
        for (int j = V; j >= 0; j--) {
            for (int k = 0; k < s; k++) {
                if (j >= v[k]) {
                    dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
                }
            }
        }
    }
    printf("%d", dp[V]);

    return 0;
}

/*
参考：https://www.acwing.com/problem/content/9/
样例输入:
3 5
2
1 2
2 4
1
3 4
1
4 5

样例输出：
8
*/