/*
适用于边稀疏图的最小生成树算法，复杂度是O(E*log(E))。
Kruskal算法按照边权值从小到大顺序查看一遍，如果不产生环（重边也算环），就把当前这条边加入到生成树中。
*/
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX_V = 50 + 1;
const int MAX_E = 50 * 49 / 2;

// 定义并查集用到的函数
int father[MAX_V];
void init(int V){
    // 注意：题目中顶点从1编号
    for(int i = 1; i <= V; i++) father[i] = i;
}
int find(int x){
    if(x == father[x]) return x;
    return (father[x] = find(father[x]));
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    father[x] = y;
}
bool same(int x, int y){
    return find(x) == find(y);
}

// 定义图数据结构
struct edge{
    int from, to; 
    int cost;
} edges[MAX_E];
int cmp(edge e1, edge e2){
    return e1.cost < e2.cost;
}
int V, E;

int kruskal(){
    int ans = 0;
    // 初始化并查集
    init(V);
    // 边排序 O(E*log(E))
    sort(edges, edges + E, cmp);
    // kruskal  O(E*alpha(V))  （其中alpha是阿克曼函数的反函数，比log更快。）
    for(int i = 0; i < E; i++){
        int from = edges[i].from;
        int to = edges[i].to;
        if(!same(from, to)){
            ans += edges[i].cost;
            unite(from, to);
        }
    }
    return ans;
}

int main(){
    freopen("in.txt", "r", stdin);
    while(scanf("%d%d", &V, &E) == 2 && V != 0){
        for(int i = 0; i < E; i++){
            scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].cost);
        }
        printf("%d\n", kruskal());
    }
    return 0;
}
/*
参考：OpenJudge 1287：Networking
样例输入:
1 0

2 3
1 2 37
2 1 17
1 2 68

3 7
1 2 19
2 3 11
3 1 7
1 3 5
2 3 89
3 1 91
1 2 32

5 7
1 2 5
2 3 7
2 4 8
4 5 11
3 5 10
1 5 6
4 2 12

0
样例输出：
0
17
16
26
*/