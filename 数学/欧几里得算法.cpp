#include <iostream>
using namespace std;

// 欧几里得算法
// 求两个非负整数a和b的最大公约数
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 扩展欧几里得算法
// 解x和y，使得 a * x + b * y = gcd(a, b)，并返回a和b的最大公约数
// 解x1和y1，使得 a1 * x1 + b1 * y1 = gcd(a1, b1)，其中 a1 = b, b1 = a % b
// 解x2和y2，使得 a2 * x2 + b2 * y2 = gcd(a2, b2)，其中 a2 = b1, b2 = a1 % b1
// 解xn和yn，使得 an * xn + bn * yn = gcd(an, bn)，其中 an = bn-1, bn = an-1 % bn-1
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

// 更便于理解的写法
int extgcd_v2(int a, int b, int& x, int& y) {
    int d;
    if(b == 0) {
        d = a;
        x = 1;
        y = 0;
    }else if(a % b == 0) {
        d = b;
        x = 0;
        y = 1;
    }else {
        int x1, y1;
        d = extgcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - a / b * y1;
    }
    return d;
}

int main() {
    // 3 * x + 4 * y = 1
    int x, y;
    cout << extgcd(3, 4, x, y) << endl;
    cout << x << " " << y << endl;
}