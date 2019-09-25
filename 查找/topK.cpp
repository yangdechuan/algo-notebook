/*
题目：
无序数组中找第K大元素。

参考：LeetCode: 215. Kth Largest Element in an Array
 */
#include<vector>
#include<queue>

using namespace std;

/*
方法：
先构造一个小根堆。遍历数组将每个元素插入堆，过程中，如果堆的大小超过k，弹出最小元素，使堆大小固定为k。
最后，堆中的最小元素即为数组的第k大元素。

时间复杂性：O(N*log(K))
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> que; // 小根堆
        for(int x: nums){
            que.push(x);
            if(que.size() > k) que.pop();
        }
        return que.top();
    }
};

/*
方法：
用快排的方法将数组分成两部分，只在其中一部分里找第K大元素，递归这个操作。

时间复杂性：O(N)
f(n) = n + f(n/2)  ==>  f(n) = 2*n   ==>  O(N)
 */
class Solution {
public:
    int ans;
    int findKthLargest(vector<int>& nums, int k) {
        findK(nums, k, 0, nums.size() - 1);
        return ans;
    }
    void findK(vector<int>& nums, int k, int left, int right){
        int tmp = nums[left];
        int i = left, j = right + 1;
        while(i < j){
            i++;
            while(i <= right && nums[i] >= tmp) i++; // 找第一个小于tmp的位置
            j--;
            while(j >= left && nums[j] < tmp) j--;  // 找第一个大于等于tmp的位置
            if(i < j) swap(nums[i], nums[j]);  // 如果i在j左面，就交换。
        }
        // 此时j是从右往左第一个大于等于nums[left]的位置;
        // 并且j左侧的元素一定都大于nums[left]
        swap(nums[left], nums[j]); 
        // 此时j左侧都大于等于nums[j]，j右侧都小于nums[j]。
        if(j - left + 1 == k){
            ans = nums[j];
            return;
        }else if(j - left + 1 < k){
            findK(nums, k - (j - left + 1), j + 1, right);
        }else{
            findK(nums, k, left, j - 1);
        }
    }
};