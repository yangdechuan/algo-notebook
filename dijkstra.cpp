#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int MAX_E = 100;
const int MAX_V = 100;
const int INF = 0x3f3f3f3f;

int V, E;  // V是顶点数，E是边数。
int d[MAX_V];  // d[i] 是从s到i的最短距离

/* 
1. 邻接矩阵
时间复杂性：O(V^2 + V^2) = O(V^2)
如果用邻接表，复杂度为O(V^2 + E) = O(V^2)
*/
int A[MAX_V][MAX_V];  // A[u][v]表示e=(u, v)的权值，不存在这条边时设为INF。
bool used[MAX_V];  // used[i]=true表示已经求出s到i的最短路径
void dijkstra1(int s){
    fill(d, d + V, INF);
    d[s] = 0;
    fill(used, used + V, false);

    while(true){// 最多循环V次
        // 找下一个距离s最短的顶点u
        // 复杂度为O(V^2)
        int u = -1;
        for(int i = 0; i < V; i++){
            if(!used[i] && (u == -1 || d[i] < d[u])){
                u = i;
            }
        }
        if(u == -1) break;
        // 对每个u可达的顶点v，更新d[v]。
        // 复杂度为O(V^2)，如果是邻接表，这部分的复杂度可降到O(E)
        for(int i = 0; i < V; i++){
            if(A[u][i] != INF){
                d[i] = min(d[i], d[u] + A[u][i]);
            }
        }
        used[u] = true; // s到u的最短路径已经求出来了
    }
}

/*
2. 邻接表 + 堆优化
时间复杂性：O(E*log(V))
*/
struct edge {int to, cost;};
vector<edge> G[MAX_V];  // 图的邻接表表示
void dijkstra2(int s){
    typedef pair<int, int> P;  // second是顶点编号，first是s到该顶点的最短距离。
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();
        int u = p.second;
        if(p.first > d[u]) continue; // 重要：如果这是旧的结点，忽略它。
        for(int i = 0; i < G[u].size(); i++){
            edge e = G[u][i];
            if(d[e.to] > d[u] + e.cost){
                d[e.to] = d[u] + e.cost;
                que.push(P(d[e.to], e.to)); // 注意： 只插入，并没有替换原来的e.to结点
            }
        }
    }
}
