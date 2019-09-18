/*
最坏情况时间复杂性：O(n^2)
平均情况时间复杂性：O(n*log(n))
稳定性：快速排序是不稳定的排序方法
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> nums = {1, 5, 2, 2, 4, 3, 9, 2};

// 标准做法（方便应用于链表排序）
int partition(int left, int right) {
    int pivot = nums[left];  // 主元
    int i = left;
    int j = left + 1;
    while (j <= right) {
        if (nums[j] < pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
        j++;
    }
    swap(nums[left], nums[i]);
    return i;
}
// 一般教辅材料里的做法
int partition2(int left, int right) {
    int pivot = nums[left];  // 算法导论中叫它主元（pivot element）
    int i = left + 1, j = right;
    while (i <= j) {
        // 从左往右，找第一个（大于）tmp的位置
        while (i <= right && nums[i] <= pivot) i++;
        // 从右往左，找第一个（小于等于）tmp的位置
        while (nums[j] > pivot) j--;
        // 交换i和j位置的元素
        if (i < j) swap(nums[i], nums[j]);
    }
    // 此时j是从右往左第一个小于等于nums[left]的位置;
    // 并且j左侧的元素一定都小于等于nums[left]（理由是此时i在j的右侧，并且i左侧元素小于等于nums[left]）
    swap(nums[left], nums[j]);
    return j;
}

void qsort(int left, int right) {
    if (left >= right) return;
    int q = partition(left, right);
    qsort(left, q - 1);
    qsort(q + 1, right);
}

int main() {
    qsort(0, nums.size() - 1);
    for (int x : nums) {
        cout << x << " ";
    }
}