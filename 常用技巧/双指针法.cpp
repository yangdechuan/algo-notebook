/*
题目描述：
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 >= s
的长度最小的连续子数组。 如果不存在符合条件的连续子数组，返回 0。

参考：LeetCode 209. Minimum Size Subarray Sum
*/
#include <vector>
using namespace std;

class Solution {
   public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        int i = 0, j = 0;
        int sum = 0;
        while (1) {
            while (j < n && sum < s) {
                sum += nums[j];
                j++;
            }
            if (sum < s) break;
            // [i, j) 是满足“sum>=s”且"从i开始"的最小区间
            ans = min(ans, j - i);
            sum -= nums[i];
            i++;
        }
        if (ans == n + 1) ans = 0;
        return ans;
    }
};