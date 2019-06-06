/*
最坏情况时间复杂性：O(n*log(n))
最坏情况时间复杂性：O(n*log(n))
辅助空间：O(n)
稳定性：快速排序是稳定的排序方法
*/
#include <cstdio>

const int MAXN = 100;
int nums[MAXN];  // 待排序数组
int tmp[MAXN];   // 一个辅助数组

// 归并 a[left:mid]  a[mid+1:right] （包含边界）
void merge(int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];
    }
    while (i <= mid) tmp[k++] = nums[i++];
    while (j <= right) tmp[k++] = nums[j++];
    // 将排序后的元素，全部都整合到数组a中。
    for (k = left; k <= right; k++) nums[k] = tmp[k];
}

// 归并排序
void merge_sort(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, mid, right);
}