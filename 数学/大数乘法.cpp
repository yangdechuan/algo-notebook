#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    // 输入字符串形式的被乘数和乘数，返回字符串形式的积。
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n1 = num1.size();
        int n2 = num2.size();
        if(n1 == 1 && num1[0] == '0') return "0";
        if(n2 == 1 && num2[0] == '0') return "0";
        vector<int> vec(n1 + n2, 0);
        for(int i = 0; i < n1; i++){
            int carry = 0;
            for(int j = 0; j < n2; j++){
                int tmp = (num1[i] - '0') * (num2[j] - '0') + vec[i + j] + carry;
                vec[i + j] = tmp % 10;
                carry = tmp / 10;
            }
            if(carry > 0){
                vec[i + n2] += carry;
            }
        }
        int start = n1 + n2 - 1;
        while(vec[start] == 0) start--;
        if(start == -1) return "0";
        string ans = "";
        for(int i = start; i >= 0; i--){
            ans += ('0' + vec[i]);
        }
        return ans;
    }
};

int main(){
    string ans = Solution().multiply("123", "456");
    cout << ans << endl;  // 56088
    return 0;
}