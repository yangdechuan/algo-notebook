#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


vector<int>::iterator my_partition(vector<int>::iterator first, vector<int>::iterator last, function<bool(int)> pred) {
    auto fast = first;
    auto slow = first;
    while(fast < last) {
        if(pred(*fast)) {
            swap(*fast, *slow);
            slow++;
        }
        fast++;
    }
    return slow;
}


void my_quick_sort(vector<int>::iterator first, vector<int>::iterator last) {
    if(first >= last) {
        return;
    }
    int pivot = *first;
    // 定义一个lambda表达式
    auto pred = [=](int x) { return x < pivot; };
    // 分割。重排这个范围，使得谓语对其返回true的元素在前，返回false的在后，并返回指向第二组元素首元素的迭代器
    // 模板库 partition 算法
    // auto mid = partition(first + 1, last, pred);
    // 复现 partition
    auto mid = my_partition(first + 1, last, pred);
    swap(*first, *(mid - 1));
    my_quick_sort(first, mid - 1);
    my_quick_sort(mid, last);
}


int main() {
    vector<int> vec = {6, 1, 2, 1, 6, 3, 8, 5};
    // 排序
    // 模板库 sort 算法
    // sort(vec.begin(), vec.end());
    // 复现 sort
    my_quick_sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}
