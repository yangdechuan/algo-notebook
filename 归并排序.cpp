#include <cstdio>

const int MAXN = 100;
int a[MAXN];
int tmp[MAXN];

// 归并 a[start:mid]  a[mid+1:end] （包含边界）
void merge(int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];

    while (j <= end) tmp[k++] = a[j++];
    // 将排序后的元素，全部都整合到数组a中。
    for (i = 0; i < k; i++) a[start + i] = tmp[i];
}
void merge_sort(int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, mid, end);
}

int main() {
    for (int i = 1; i <= 10; i++) {
        scanf("%d", &a[i]);
    }
    merge_sort(1, 10);
    for (int i = 1; i <= 10; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
