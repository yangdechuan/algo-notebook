/*
算法参考博客：http://blog.csdn.net/github_35890787/article/details/77163081
*/
#include <iostream>
#include <vector>
using namespace std;

// 参考算法导论
vector<int> getPrefix(string pattern) {
    // 加一个空字符使得pattern从1开始编号
    // 这样prefix和pattern都是从1开始编号
    // pattern[1:m]  <==>  prefix[1:m]
    int m = pattern.size();
    pattern = " " + pattern;

    // prefix[i]表示pattern[1:i]子串的最长公共前后缀长度
    vector<int> prefix(m + 1);
    // 第1个字符
    prefix[1] = 0;
    int k = 0;  // k = prefix[1]
    // 第2到第m个字符
    for (int i = 2; i <= m; i++) {
        // k是pattern[1:i-1]的最长公共前后缀
        while (k > 0 && pattern[i] != pattern[k + 1]) {
            k = prefix[k];
        }
        if (pattern[i] == pattern[k + 1]) {
            k++;
        }
        prefix[i] = k;
    }
    return prefix;
}

void kmp(string text, string pattern) {
    vector<int> prefix = getPrefix(pattern);
    // i是text的下标，q是pattern的下标，都是从0开始
    int q = 0;
    for (int i = 0; i < text.size(); i++) {
        while (q > 0 && text[i] != pattern[q]) {
            q = prefix[q];
        }
        if (text[i] == pattern[q]) {
            q++;
        }
        if (q == pattern.size()) {
            cout << "Pattern occurs with shift " << i - q + 1 << endl;
            q = prefix[q];
        }
    }
}

int main() {
    string text = "He like Beijing, I also like Beijing";
    string pattern = "Beijing";
    kmp(text, pattern);
}
