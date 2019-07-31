/*
给定n个非负整数代表n个柱形条的高度，每个柱形条的宽度为1，返回该柱形图中最大矩形的面积。
参考：Leetcode 84. Largest Rectangle in Histogram
 */
#include<vector>
#include<stack>

using namespace std;


// 单调栈算法
// 1. 此题的本质是找到每个柱形条左边和右边最近的比自己低的矩形条，然后用宽度乘上当前柱形条的高度作为备选答案。
// 2. 解决此类问题的经典做法是单调栈，维护一个单调递增的栈，如果当前柱形条i的高度比栈顶要低，则栈顶元素cur出栈。
// 出栈后，cur右边第一个比它低的柱形条就是i，左边第一个比它低的柱形条是当前栈中的top。
// 不断出栈直到栈为空或者柱形条i不再比top低。
// 3. 满足2之后，当前矩形条i进栈。
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // 插入一个0，保证最后栈空。
        int n = heights.size();
        int ans = 0;
        stack<int> sta;
        for(int i = 0; i < n; i++){
            // 第i个柱子比栈顶柱子高或者等，压栈。
            if(sta.empty() || heights[i] >= heights[sta.top()]){
                sta.push(i);
            }else{
                // 第i个柱子高度小于栈顶柱子的高度
                // 此时，可以得知栈顶柱子左右第一个比它小的位置
                while(!sta.empty() && heights[i] < heights[sta.top()]){
                    // 取出所有比i高的柱子
                    int cur = sta.top();
                    sta.pop();
                    int lessFromRight = i;  // 右侧第一个比cur小的位置
                    int lessFromLeft = (!sta.empty()) ? sta.top() : -1;  // 左侧第一个比cur小的位置
                    ans = max(ans, heights[cur] * (lessFromRight - lessFromLeft - 1));
                }
                // 此时，第i个柱子比栈顶柱子高或者等。
                sta.push(i);
            }
        }
        return ans;
    }
};

// 此外，这道题还有另一个更直观的解法
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;
        int ans = 0;
        vector<int> lessFromLeft(n);  // 左面第一个比i小的位置
        vector<int> lessFromRight(n); // 右面第一个比i小的位置
        lessFromLeft[0] = -1;
        lessFromRight[n - 1] = n;
        for(int i = 1; i < n; i++){
            int p = i - 1;
            while(p >= 0 && heights[p] >= heights[i]) p = lessFromLeft[p];
            lessFromLeft[i] = p;
        }
        for(int i = n - 2; i >= 0; i--){
            int p = i + 1;
            while(p < n && heights[p] >= heights[i]) p = lessFromRight[p];
            lessFromRight[i] = p;
        }
        for(int i = 0; i < n; i++){
            ans = max(ans, heights[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
        }
        return ans;
    }
};