/*
树状数组(Binary Indexed Tree, BIT)是能够O(logn)复杂度下完成下述操作的数据结构
给定一个初始值全为0的数列 a1, a2, ..., an
1. 给定i，计算a1 + a2 + ... + ai
2. 给定i和x，执行ai = ai + x
*/

const int MAXN = 1000;
int bit[MAXN];  // bit的每个值对应线段树的一个区间
int n;          // n个元素

// i的二进制最低非0位对应的幂
int lowbit(int i) { return i & -i; }

// 计算a1 + a2 + ... + ai
int query(int i) {
    int s = 0;
    while (i) {
        s += bit[i];
        i -= lowbit(i);  // 区间i的前一个区间
    }
    return s;
}

// ai = ai + x
void add(int i, int x) {
    while (i <= n) {
        bit[i] += x;
        i += lowbit(i);  // 下一个覆盖区间i的区间
    }
}