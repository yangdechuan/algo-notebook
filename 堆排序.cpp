/*
最坏情况时间复杂性：O(n*log(n))
平均情况时间复杂性：O(n*log(n))
稳定性：快速排序是不稳定的排序方法
*/
#include <iostream>
#include <queue>

using namespace std;

vector<int> heapSort(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    // 建小根堆, 时间复杂度：O(n)
    // 注意:priority_queue默认是大根堆
    // 这里我们建小根堆
    priority_queue<int, vector<int>, greater<int>> que(nums.begin(), nums.end());
    // 每次从堆中取最小元素 O(n*log(n))
    for (int i = 0; i < n; i++) {
        ans[i] = que.top();
        que.pop();
    }
    return ans;
}

int main() {
    vector<int> vec = {1, 3, 5, 4, 2, 5, 0, 5};
    vector<int> ans = heapSort(vec);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}