#include <cstdio>

const int MAXN = 50000 * 3;
int father[MAXN];

// 初始化n个元素
void init(int n) {
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
}

// 查询树的根
int find(int x) {
    if (father[x] == x) {
        return x;
    }
    return (father[x] = find(father[x]));  // 路径压缩
}

// 合并x和y所属的集合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    father[x] = y;
}

// 判断x和y是否属于同一个集合
bool same(int x, int y) { return find(x) == find(y); }

int N, K;
int main() {
    freopen("in.txt", "r", stdin);
    int ans = 0;  // 假话的数目
    scanf("%d%d", &N, &K);
    // 0<=i<N时候，father[i]表示“i属于A类”
    // N<=i<2N时候，father[i]表示“i属于B类”
    // 2N<=i<3N时候，father[i]表示“i属于C类”
    // 如果i和j在并查集的同一个集合中，表示这i和j对用的两个情况同时发生或者同时不发生。
    init(3 * N);
    for (int i = 0; i < K; i++) {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (x > N || y > N) {
            ans++;
            continue;
        }
        x--;
        y--;
        if (d == 1) {  // x和y是同类
            if (same(x, y + N) || same(x, y + 2 * N)) {
                ans++;
            } else {
                unite(x, y);                  // x和y同时是A类
                unite(x + N, y + N);          // x和y同时是B类
                unite(x + 2 * N, y + 2 * N);  // x和y同时是C类
            }
        } else {  // x吃y
            if (same(x, y) || same(x, y + 2 * N)) {
                ans++;
            } else {
                unite(x, y + N);          // x是A类，y是B类
                unite(x + N, y + 2 * N);  // x是B类，y是C类
                unite(x + 2 * N, y);      // x是C类，y是A类
            }
        }
    }
    printf("%d", ans);

    return 0;
}
/*
参考：OpenJudge 1182：食物链
样例输入:
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5

样例输出：
3
*/