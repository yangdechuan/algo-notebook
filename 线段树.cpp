/*
线段树(Segment Tree)擅长处理区间
树上每个节点都维护一个区间。根节点维护整个区间，每个节点维护的是父亲的区间二等分后的其中一个子区间。
*/
#include <algorithm>
using namespace std;

const int MAXN = 1 << 17;
const int INF = 0x3f3f3f3f;
// 存储线段树的全局数组（从0开始编号）
int n;
int dat[2 * MAXN - 1];

// 初始化线段树
void init(int n_) {
    n = 1;
    // 为简单起见，把元素个数扩大到2的幂
    while (n < n_) n *= 2;
    // 把所有元素值都设为无穷大
    for (int i = 0; i < 2 * n - 1; i++) dat[i] = INF;
}

// 把第k个元素更新为a
void update(int k, int a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }
}

// 求[a, b)的最小值
// k表示第当前在第k个节点，[l, r)表示该节点对应的区间
// 调用: query(a, b, 0, 0, n)
int query(int a, int b, int k, int l, int r) {
    if (b <= l || a >= r) return INF;
    if (a <= l && b >= r) return dat[k];
    int v1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
    int v2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return min(v1, v2);
}