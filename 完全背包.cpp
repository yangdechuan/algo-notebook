#include<cstdio>
#include<algorithm>

using namespace std;

// 有 N 种物品和一个容量是 V 的背包，每种物品都有无限件可用。
int N, V;
// 第 i 种物品的体积是 v[i]，价值是 w[i]。
int v[1000 + 1], w[1000 + 1];
int dp[1000 + 1];

int main(){
    scanf("%d%d", &N, &V);
    for(int i = 1; i <= N; i++){
        scanf("%d%d", &v[i], &w[i]);
    }
    for(int i = 0; i <= V; i++) dp[i] = 0;
    // DP
    for(int i = 1; i <= N; i++){
        for(int j = v[i]; j <= V; j++){ // 与01背包唯一不同地方，从前往后计算。
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    printf("%d", dp[V]);

    return 0;
}

/*
参考：https://www.acwing.com/problem/content/3/
样例输入:
4 5
1 2
2 4
3 4
4 5

样例输出：
10
*/