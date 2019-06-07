/*
秦九韶定理：
m1、m2、m3两两互质，a1、a2、a3都是整数，则下列同余方程组有解，且在模m1*m2*m3下解唯一；
x = a1 (mod m1)
x = a2 (mod m2)
x = a3 (mod m3)

解:
取c1、c2、c3使得下面式子成立
l1 = m2 * m3 * c1  =>  l1 = 1 (mod m1)
l2 = m1 * m3 * c2  =>  l2 = 1 (mod m2)
l3 = m1 * m2 * c3  =>  l3 = 1 (mod m3)
则，
x = a1 * l1 + a2 * l2 + a3 * l3 即为所求解。
*/
#include <cstdio>

int main() {
    freopen("in.txt", "r", stdin);
    int p, e, i, d;
    int idx = 1;
    while (scanf("%d%d%d%d", &p, &e, &i, &d) == 4 && p != -1) {
        /*
        x = p (mod 23)
        x = e (mod 28)
        x = i (mod 33)
        解：
        l1 = 28 * 33 * c1 = 1 (mod 23)
        l2 = 23 * 33 * c2 = 1 (mod 28)
        l3 = 23 * 28 * c3 = 1 (mod 33)
        解得，c1 = 6, c2 = 19, c3 = 2
        所以，
        l1 = 28 * 33 * 6 = 5544
        l2 = 23 * 33 * 19 = 14421
        l3 = 23 * 28 * 3 = 1288
        所以，
        x = 5544 * p + 14421 * e + 1288 * i (mod 23*28*33)
         */
        int x = (5544 * p + 14421 * e + 1288 * i) % (23 * 28 * 33);
        int ans;
        if (x > d) {
            ans = x - d;
        } else if (x == d) {
            ans = 23 * 28 * 33;
        } else {
            ans = x + 23 * 28 * 33 - d;
        }
        printf("Case %d: the next triple peak occurs in %d days.\n", idx++,
               ans);
    }
}
/*
参考：1006: Biorhythms
样例输入:
0 0 0 0
0 0 0 100
5 20 34 325
4 5 6 7
283 102 23 320
203 301 203 40
-1 -1 -1 -1

样例输出：
Case 1: the next triple peak occurs in 21252 days.
Case 2: the next triple peak occurs in 21152 days.
Case 3: the next triple peak occurs in 19575 days.
Case 4: the next triple peak occurs in 16994 days.
Case 5: the next triple peak occurs in 8910 days.
Case 6: the next triple peak occurs in 10789 days.
*/