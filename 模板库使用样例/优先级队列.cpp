#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    struct P {
        int x, y;
        P() : x(0), y(0) {}
        P(int xx, int yy) : x(xx), y(yy) {}
        // 结构体变量不可比较，所以必须重载运算符<，使之可以比较。
        bool operator<(
            P p) const {  // const修饰函数，表示函数内不能修改对象的数据成员。
            if (x == p.x) return y < p.y;
            return x < p.x;
        }
    };
    // 四种初始化结构体变量的方法
    P p1 = {1, 2};
    P p2(3, 4);
    P p3;
    p3.x = 5;
    p3.y = 6;
    P p4;  // 不可以写成 P = p4();

    // 注意，用less时候必须定义operator<
    // 同理，用greater时候必须定义operator>
    // priority_queue<P, vector<P>, less<P>> que;  // 大根堆
    // priority_queue<P, vector<P>, greater<P>> que;  // 小根堆
    priority_queue<P> que;  // 默认大根堆
    que.push(p1);
    que.push(p2);
    que.push(p3);
    que.push(p4);
    while (!que.empty()) {
        cout << que.top().x << "," << que.top().y << endl;
        que.pop();
    }
    /*
    输出结果：
    5,6
    3,4
    1,2
    0,0
     */
}