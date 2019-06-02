/*
算法参考博客：http://blog.csdn.net/github_35890787/article/details/77163081
*/
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100;
//next[x]表示前x个字符的最长公共前后缀。
//显然下标从1开始是有意义的，为了方便我们置next[0]=1。
int next[MAXN];

void getNext(string str) {
    next[0] = next[1] = 0;
    int comLength = 0;
    //i为字符串下标，字符串编号从0开始。
    for(int i = 1; i < str.size(); i++) {
        //设str前i个字符为substr
        //如果substr存在公共前后缀（comLength > 0），
        //并且前缀的下一个字符不等于substr的下一个字符(str[i] != str[comLength])
        while(comLength > 0 && str[i] != str[comLength]) {
            //更新最长公共前后缀
            comLength = next[comLength];
        }
        if(str[i] == str[comLength]) {
            comLength++;
        }//else comLength一定是0
        //计算str[0-i]子串的最长公共前后缀
        next[i + 1] = comLength;
    }
}
//pattern在text中出现的位置
void kmp(string text, string pattern) {
    //q为已匹配的字符串长度
    int q = 0;
    //遍历text
    for(int i = 0; i < text.size(); i++) {
        while(q > 0 && text[i] != text[q]) {
            q = next[q];//下一个字符不匹配
        }
        if(text[i] == text[q]) {
            q++;//下一个字符匹配
        }
        if(q == pattern.size()) {//整个pattern都匹配了
            cout << "Pattern occurs with shift " << i - q + 1 << endl;
            q = next[q];//寻找下一次匹配
        }
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    getNext(pattern);
    kmp(text, pattern);
    return 0;

}
