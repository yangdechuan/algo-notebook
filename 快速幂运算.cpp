#include <iostream>
using namespace std;

/*
求x的n次幂
时间复杂度：O(log(n))
*/
int pow(int x, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) ans = ans * x;
        x = x * x;
        n >>= 1;
    }
    return ans;
}

int main() {
    cout << pow(2, 5) << endl;
    return 0;
}
