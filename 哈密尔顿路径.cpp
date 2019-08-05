/*
参考：LeetCode: 847. Shortest Path Visiting All Nodes
 */
#include<vector>
#include<queue>

using namespace std;


/*
法一：
动态规划
每个状态可以表示为已访问结点的子集和第一个访问的结点：
(cover, head)： cover表示集合，head表示当前结点
dp(cover + {j}, j) = min_i { dp(cover, i) }

那么，最终答案是： max_i { dp(V, i) }
 */
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, n * n));
        for(int i = 0; i < n ;i++) {
            dp[1 << i][i] = 0;
        }
        for(int cover = 0; cover < 1 << n; cover++) {
            bool repeat = true;
            while(repeat) {
                repeat = false;
                for(int head = 0; head < n; head++) {
                    int d = dp[cover][head];
                    for(int nxt: graph[head]) {
                        int cover2 = cover | (1 << nxt);
                        if(d + 1 < dp[cover2][nxt]) {
                            dp[cover2][nxt] = d + 1;
                            if(cover == cover2) repeat = true;
                        }
                    }
                }
            }
        }
        int ans = n * n;
        for(int cand: dp[(1 << n) - 1]) {
            ans = min(ans, cand);
        }
        return ans;
    }
};

/*
法二：
使用BFS的方式
dp(S, i)表示，从i开始走的关于集合S的哈密尔顿路长度（S包含i）
dp(S + {j}, j) = min( dp(S, i) + 1)  其中i和j相连。
 */
class Solution2 {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, n * n));
        queue<pair<int, int>> que;
        for(int i = 0; i < n; i++){
            que.push(make_pair(1 << i, i));
            dp[1 << i][i] = 0;
        }
        while(!que.empty()){
            int S = que.front().first;
            int i = que.front().second;
            // 因为是BFS,每搜索一层，路径长度加1
            // 所以，第一个包含所有结点的路径即为最短路径
            if(S == (1 << n) - 1){
                return dp[S][i];
            }
            que.pop();
            for(int& j : graph[i]){
                // 注意：S包含j的情况也是合理的
                // 因为哈密尔顿路允许路过同一个结点多次
                if(dp[S][i] + 1 < dp[S | (1 << j)][j]){
                    dp[S | (1 << j)][j] = dp[S][i] + 1;
                    que.push(make_pair(S | (1 << j), j));
                }
            }
        }
        return 0;
    }
};