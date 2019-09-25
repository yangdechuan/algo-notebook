## 快速幂
时间复杂度：O(logn)
- 计算整数x的n次幂
- 计算矩阵A的n次幂

## 斐波那契数列
f(0) = 0  
f(1) = 1  
f(n) = f(n - 1) + f(n - 2)  
方法一：动态规划  
时间复杂度：O(n)  
dp(n) = dp(n - 1) + dp(n - 2)  
方法二：矩阵快速幂  
时间复杂度：O(logn)，但是隐含的时间常数较大。

## 约瑟夫问题
n个人编号0,...,n-1围成一圈，顺时针从1开始报数，每次报到m的人被杀掉并移出去，
然后从下一个人开始报数，直到剩余一个人；求最后活着的人的编号。  
解：  
dp(i)表示一共i个人最后活着的人的编号  
dp(1) = 0  
dp(i) = (dp(i - 1) + m) % i

## 素数
- 判断n是否是素数：只需判断n能否被2-sqrt(n)之间的数整数
- 枚举n以内的素数：埃氏筛法

## 欧几里得算法
### 欧几里得算法
求两个非负整数a和b的最大公约数
```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
```
### 扩展欧几里得算法
解x和y，使得 a*x + b*y = gcd(a, b)  
> 定理：一定存在整数x和y使得ax+by=gcd(a,b)
```cpp
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
```

## 秦九韶定理
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