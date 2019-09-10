# 最短路径问题
## Dijkstra
把图中的所有顶点分两组，第一组：已求完最短路径的顶点，第二组：未求完最短路径的顶点，按最短路径长度递增的顺序逐个把第二组的顶点加到第一组。
```cpp
const int MAXN = 1000;
struct edge{
    int to, cost;
}
vector<edge> G[MAXN];  // 图的邻接表表示
int d[MAXN];  // d[i] 是从s到i的最短距离
// 使用优先级队列优化
typedef pair<int, int> P;  // second是顶点编号，first是s到该顶点的最短距离。
priority_queue<P, vector<P>, greater<P>> que;
```

## Bellman-Ford
dp(i, v)表示从起始点开始经过不超过i条边到v的最短路径长度  
dp(i, v) = min{ dp(i - 1, v), min{ dp(i - 1, u) + d[u][v] } }

## Floyd
dp(k, i, j) 表示从i到j，中间只可以经过{0, 1, ..., k}这些顶点的最短路径长度  
dp(k, i, j) = min{ dp(k - 1, i, k) + dp(k - 1, k, j) }

| | 解决问题 | 复杂度 | 方法 | 特点 |
| :- |:-: |:-: |:-: |:-: |
| Dijkstra | 单源最短路径 | O(E*logV) | 贪心方法 | 边权非负 |
| Bellman-Ford | 单源最短路径 | O(E*V) | 动态规划 | 可以检测负环|
| Floyd | 任意两点最短路径 | O(V^3) | 动态规划 | 不允许有负环 |

# 最小生成树
## Kruskal
适用于边稀疏图的最小生成树算法，复杂度是O(E*log(E))  
Kruskal算法按照边权值从小到大顺序查看一遍，如果不产生环（重边也算环），就把当前这条边加入到生成树中。

## Prim
适用于边稠密图的最小生成树算法，复杂度是O(V^2)  
初始化只有一个顶点的树X，然后贪心地选取X和其他顶点之间相连的最小权值的边，并把它加到X中；不断这个操作，直到把所有顶点纳入X中，就得到最小生成树。