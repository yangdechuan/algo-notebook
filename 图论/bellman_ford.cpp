#include <cstdio>
#include <vector>

using namespace std;

const int MAX_E = 100;
const int MAX_V = 100;
const int INF = 0x3f3f3f3f;

// 从顶点from到顶点to的权值为cost的边
struct edge {
    int from, to, cost;
};
// 既不是邻接矩阵也不是邻接表，只是一个保存所有边的数组
edge es[MAX_E];

int V, E;      // V是顶点数，E是边数。
int d[MAX_V];  // d[i] 是从s到i的最短距离

// 时间复杂性： O(V*E)
void bellman_ford(int s) {
    for (int i = 0; i < V; i++) d[i] = INF;
    d[s] = 0;
    // 求源点为s的单源最短路
    for (int i = 1; i <= V - 1; i++) {  // 没有负环的话，最多松弛V-1次。
        bool updated = false;
        for (int i = 0; i < E; i++) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                updated = true;
            }
        }
        if (!updated) break;  // 如果某一次不松弛，就提前退出。
    }
    // 判断负环
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
            printf("存在负环！");
            break;
        }
    }
}
