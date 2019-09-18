/*
链表快排
参考：Leetcode 148. Sort List
*/
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 快排
class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        qsort(head, NULL);
        return head;
    }
    // 排序[head, tail)区间
    void qsort(ListNode* head, ListNode* tail) {
        if (head == tail) return;
        int pivot = head->val;
        // [head, i]保存pivot以及小于pivot的元素
        ListNode* i = head;
        ListNode* j = head->next;
        while (j != tail) {
            // 如果当前元素小于pivot，将它挪到前面。
            if (j->val < pivot) {
                i = i->next;
                swap(i->val, j->val);
            }
            j = j->next;
        }
        swap(i->val, head->val);
        // 此时i等于pivot，i左侧都小于pivot，i右侧都大于等于pivot
        qsort(head, i);
        qsort(i->next, tail);
    }
};