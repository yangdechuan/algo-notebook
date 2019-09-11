#include<iostream>
using namespace std;

int n, m;
int main(){
    cin >> n >> m;
    // 假如n=8, m=3
    // 0, 1, 2, 3, 4, 5, 6, 7
    // 0, 1,    3, 4, 5, 6, 7
    // 3, 4, 5, 6, 7, 0, 1
    // 0, 1, 2, 3, 4, 5, 6
    // dp(n)表示n个人，最后存活的人的编号（编号从0开始）
    // dp(n) = (dp(n - 1) + m) % n
    int ans = 0;
    for(int i = 2; i <= n; i++){
        ans = (ans + m) % i;
    }
    // 输出从1开始编号，所以ans加1
    cout << ans + 1;

    return 0;
}
/*
参考：牛客网： 环形链表的约瑟夫问题
*/