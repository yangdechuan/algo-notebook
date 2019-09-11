/*
题目：
给定一个只包含非负整数的数组nums，和一个整数m，将nums划分为m个非空子数组。实现算法使得这些数组的最大和最小。
思路：
出现“最大最小”字样，要首先想到用“二分答案”来做。

参考：LeetCode: 410. Split Array Largest Sum
 */
#include<vector>
#include<algorithm>
 
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, int m, long long ans){
        // 判断最大和为ans是否可能
        int cnt = 1;
        long long tmpSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(tmpSum + nums[i] <= ans){
                tmpSum += nums[i];
            }else{
                tmpSum = nums[i];
                cnt++;
            }
        }
        return cnt <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int maxVal = 0;
        long long sumVal = 0;
        for(int i = 0; i < nums.size(); i++){
            maxVal = max(maxVal, nums[i]);
            sumVal += nums[i];
        }
        // 每个子数组要么有一个元素，要么有n个元素，要么在这之间。
        // 所以答案只能在[l, r]区间，所以在[l, r]区间找答案。
        long long l = maxVal, r = sumVal;
        long long ans;
        // 二分查找
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if(check(nums, m, mid)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};