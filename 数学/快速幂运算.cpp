#include <iostream>
using namespace std;

/*
求x的n次幂
时间复杂度：O(log(n))
*/
int pow1(int x, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) ans = ans * x;
        x = x * x;
        n >>= 1;
    }
    return ans;
}

int pow2(int x, int n) {
    if (n == 0) return 1;
    int ans = pow2(x * x, n / 2);
    if (n & 1) ans = ans * x;
    return ans;
}

int main() {
    cout << pow2(2, 5) << endl;
    return 0;
}
