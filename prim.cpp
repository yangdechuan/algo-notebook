/*
适用于边稠密图的最小生成树算法，复杂度是O(V^2)
初始化只有一个顶点的树X，然后贪心地选取X和其他顶点之间相连的最小权值的边，并把它加到X中；
不断这个操作，知道把所有顶点纳入X中，就得到最小生成树。
*/
#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

const int MAX_V = 100;
const int INF = 100000 + 1;

int A[MAX_V][MAX_V]; // 邻接矩阵
int vis[MAX_V]; // 顶点是否包含在集合X中
int V; // 顶点数
int mincount[MAX_V]; // 从集合X出发的边到每个顶点的最小权值
int prim(){
    int ans = 0;
    for(int i = 1; i < V; i++){
        mincount[i] = A[0][i];
        vis[i] = 0;
    }
    // 第0号定点
    mincount[0] = 0;
    vis[0] = 1; 
    // 剩下V-1个顶点
    for(int i = 1; i <= V - 1; i++){ 
        // 从不属于X的顶点中选取从X到其权值最小的顶点
        int v = -1;
        for(int j = 0; j < V; j++){
            if(!vis[j] && (v == -1 || mincount[j] < mincount[v])){
                v = j;
            }
        }
        vis[v] = 1;
        ans += mincount[v];
        // 更新mincount
        for(int j = 0; j < V; j++){
            if(!vis[j]){
                mincount[j] = min(mincount[j], A[v][j]);
            }
        }
    }
    return ans;
}

int main(){
    // freopen("in.txt", "r", stdin);
    while(scanf("%d", &V) == 1){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                scanf("%d", &A[i][j]);
            }
        }
        printf("%d\n", prim());
    }
    return 0;
}
/*
参考：OpenJudge 1258：Agri-Net
样例输入:
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0

样例输出：
28
*/