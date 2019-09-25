/*
算法参考博客：http://blog.csdn.net/github_35890787/article/details/77163081
*/
#include <iostream>
#include <vector>
using namespace std;

// 在text中找出pattern出现的每一个位置
void kmp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    if (m == 0) return;
    if (n == 0) return;
    // 1. 计算前缀函数 O(m)
    // prefix[i]表示pattern[0:i]的最长公共前后缀长度
    vector<int> prefix(m);
    prefix[0] = 0;
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[i] != pattern[k]) {
            k = prefix[k - 1];
        }
        if (pattern[i] == pattern[k]) k++;
        prefix[i] = k;
    }
    // 2. 匹配 O(n)
    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && text[i] != pattern[q]) {
            q = prefix[q - 1];
        }
        if (text[i] == pattern[q]) q++;
        if (q == m) {
            cout << "Pattern occurs with shift " << i - q + 1 << endl;
            q = prefix[q - 1];
        }
    }
}

int main() {
    string text = "aabaaabaaac";
    string pattern = "aabaaac";
    kmp(text, pattern);
}
