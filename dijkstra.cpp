/*
参考：2387:Til the Cows Come Home
样例输入:
5 5
1 2 20
2 3 30
3 4 20
4 5 20
1 5 100

样例输出：
90
*/
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAX_V = 1000 + 1;
const int INF = 0x3f3f3f3f;

/*
法一. 邻接矩阵
时间复杂性：O(V^2 + V^2) = O(V^2)
如果用邻接表，复杂度为O(V^2 + E) = O(V^2)
*/

/*
法二. 邻接表 + 堆优化
时间复杂性：O(E*log(V))
*/
int V, E;      // V是顶点数，E是边数。
struct edge {
    int to, cost;
};
vector<edge> G[MAX_V];  // 图的邻接表表示
int d[MAX_V];  // d[i] 是从s到i的最短距离

void dijkstra(int source){
    for(int i = 1; i <= V; i++) d[i] = INF;
    d[source] = 0;
    typedef pair<int, int> P;  // second是顶点编号，first是s到该顶点的最短距离。
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(make_pair(0, source));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int u = p.second;
        if(d[u] < p.first) continue;  // 重要：如果这是旧的结点，忽略它。
        for(int i = 0; i < G[u].size(); i++){
            edge e = G[u][i];
            int v = e.to;
            if(d[u] + e.cost < d[v]){
                d[v] = d[u] + e.cost;
                // 注意： 只插入，并没有替换原来的e.to结点，所以需要第50行代码的判断。
                // STL的priority_queue不支持decrease-key操作！
                que.push(make_pair(d[v], v)); 
            }
        }
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &E, &V);
    for(int i = 0; i < E; i++){
        int from, to, cost;
        scanf("%d%d%d", &from, &to, &cost);
        G[from].push_back({to, cost});
        G[to].push_back({from, cost});
    }
    dijkstra(V);
    printf("%d", d[1]);

    return 0;
}