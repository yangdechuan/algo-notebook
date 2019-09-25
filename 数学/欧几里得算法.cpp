#include <iostream>
using namespace std;

// 欧几里得算法
// 求两个非负整数a和b的最大公约数
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 扩展欧几里得算法
// 解x和y，使得 a*x + b*y = gcd(a, b)
// 返回a和b的最大公约数
// 一定存在整数x和y使得ax+by=gcd(a,b)
int extgcd(int a, int b, int& x, int& y) {
    int d = a;
    if (b != 0) {
        int x1, y1;
        d = extgcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - a / b * y1;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

int main() {
    // 3 * x + 4 * y = 1
    int x, y;
    cout << extgcd(3, 4, x, y) << endl;
    cout << x << " " << y << endl;
}