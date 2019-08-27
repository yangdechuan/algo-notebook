#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

/*
素数测试 O(sqrt(n))
*/
bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return n != 1;
}

/*
枚举n以内素数
埃氏筛法：
将2到n范围内所有的整数记下来；
其中最小的数字2是素数，将表中所有2的倍数都划去；
表中剩余的最小数字是3，它不能被更小的数整除，所以是素数，再将表中所有3的倍数都划去；
以此类推，如果表中剩余的最小数字是m时，m就是素数，然后将表中所有m的倍数都划去。
像这样反复操作，就能依次枚举n以内的素数
*/
vector<int> sieve(int n){
    vector<bool> is_prime(n, true);
    vector<int> ans;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            ans.push_back(i);
            for(int j = i + i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
    return ans;
}

/*
枚举区间[a, b)的素数
区间筛法：
根据sqrt(b)以内的素数，将埃氏筛法运用在[a, b）上。
*/
vector<int> segment_sieve(int a, int b){
    int sqr_b = sqrt(b);
    vector<bool> is_prime_small(sqr_b + 1, true);
    vector<bool> is_prime_big(b - a, true);
    // [2, sqrt(b)）
    for(int i = 2; i * i < b; i++) is_prime_small[i] = true;
    // 【a, b)
    for(int i = 0; i < b - a; i++) is_prime_big[i] = true;
    
    for(int i = 2; i * i < b; i++){
        if(is_prime_small[i]){
            // 划去[2, sqrt(b)）的非质数
            for(int j = i + i; j * j < b; j += i) is_prime_small[j] = false;
            // 划去[a, b)的非质数
            // (a + i - 1) / i) * i是第一个大于等于a的i的倍数
            for(int j = max(2, (a + i - 1) / i) * i; j < b; j += i){
                is_prime_big[j - a] = false;
            }
        }
    }
    vector<int> ans;
    for(int i = 0; i < b - a; i++){
        if(is_prime_big[i] && a + i >= 2) ans.push_back(a + i);
    }
    return ans;
}

int main(){
    vector<int> ans = segment_sieve(11, 19);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}