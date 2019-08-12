#include<cstdio>
#include<algorithm>

using namespace std;

// 有 N 种物品和一个容量是 V 的背包
int N, V;
// 第 i 种物品最多有 s[i] 件，每件体积是 v[i]，价值是 w[i]。
int v[100 + 1], w[100 + 1], s[100 + 1];
// dp[j] 表示背包容量不超过j的最大价值
int dp[100 + 1];

int main(){
    scanf("%d%d", &N, &V);
    for(int i = 1; i <= N; i++){
        scanf("%d%d%d", &v[i], &w[i], &s[i]);
    }
    for(int i = 0; i <= V; i++) dp[i] = 0;
    // DP
    for(int i = 1; i <= N; i++){
        for(int j = V; j>= v[i]; j--){ // 根01背包类似，从后往前计算。
            int K = min(j / v[i], s[i]);
            for(int k = 1; k <= K; k++){
                dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
            }
        }
    }
    printf("%d", dp[V]);

    return 0;
}

/*
参考：https://www.acwing.com/problem/content/4/
样例输入:
4 5
1 2 3
2 4 1
3 4 3
4 5 2

样例输出：
10
*/