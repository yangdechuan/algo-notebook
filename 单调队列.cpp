/*
求数组每个k大小的滑动窗口的最大值
参考：Leetcode 239. Sliding Window Maximum
 */
#include<vector>
#include<deque>

using namespace std;

/*
单调队列算法
每次插入新元素时候，如果队列尾部代表的元素值比当前小，把尾部元素删掉。从而保证队列是降序的。
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 队列存放数组的下标
        // 数组前面的元素一定在队列前面
        // 队列中前面的元素代表的值一定比后面的元素值大
        deque<int> que;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            while(!que.empty() && que.front() < i - k + 1){
                que.pop_front();
            }
            while(!que.empty() && nums[i] >= nums[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
            if(i >= k - 1){
                ans.push_back(nums[que.front()]);
            }
        }
        return ans;
    }
};