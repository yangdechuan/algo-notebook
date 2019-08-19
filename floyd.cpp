/*
参考：OpenJudge 4083:我爱北大
样例输入:
6
XueYiShiTang
CanYinZhongXin
XueWuShiTang
XueYiXiaoBaiFang
BaiNianJiangTang
GongHangQuKuanJi
6
XueYiShiTang CanYinZhongXin 80
XueWuShiTang CanYinZhongXin 40
XueYiShiTang XueYiXiaoBaiFang 35
XueYiXiaoBaiFang XueWuShiTang 85
CanYinZhongXin GongHangQuKuanJi 60
GongHangQuKuanJi BaiNianJiangTang 35
2
XueYiXiaoBaiFang BaiNianJiangTang
GongHangQuKuanJi GongHangQuKuanJi

样例输出：
XueYiXiaoBaiFang->(35)->XueYiShiTang->(80)->CanYinZhongXin->(60)->GongHangQuKuanJi->(35)->BaiNianJiangTang
GongHangQuKuanJi
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAXN = 30;
const int INF = 0x3f3f3f3f;
int P, Q, R;
int A[MAXN][MAXN];  // 图的邻接矩阵表示
int path[MAXN][MAXN];  // path[i][j]表示从i到j的最短路径上j的前一个顶点的序号
unordered_map<string, int> name2idx;
string idx2name[MAXN];

// 算法复杂度：O(N^3)
// 图可以有负权边，但是不允许有负环。
void floyd() {
    for (int k = 0; k < P; k++) {
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < P; j++) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> P;
    for (int i = 0; i < P; i++) {
        string name;
        cin >> name;
        name2idx[name] = i;
        idx2name[i] = name;
    }
    cin >> Q;
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < P; j++) {
            if (i == j)
                A[i][j] = 0;
            else
                A[i][j] = INF;
        }
    }
    for (int i = 0; i < Q; i++) {
        string from, to;
        int d;
        cin >> from >> to >> d;
        if (A[name2idx[from]][name2idx[to]] < d) continue;
        A[name2idx[from]][name2idx[to]] = d;
        A[name2idx[to]][name2idx[from]] = d;
    }
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < P; j++) {
            if (i != j && A[i][j] < INF)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }
    }
    floyd();
    cin >> R;
    for (int i = 0; i < R; i++) {
        string from, to;
        cin >> from >> to;
        int idx1 = name2idx[from];
        int idx2 = name2idx[to];
        string ans;
        while (idx2 != idx1) {
            int pre = path[idx1][idx2];
            int d = A[pre][idx2];
            ans = "->(" + to_string(d) + ")->" + idx2name[idx2] + ans;
            idx2 = pre;
        }
        ans = from + ans;
        cout << ans << endl;
    }
    return 0;
}