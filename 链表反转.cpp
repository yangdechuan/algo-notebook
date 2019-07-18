#include<cstdio>


 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/*
题目：最简单的反转链表
参考：LeetCode 206. Reverse Linked List
例子：
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode* nextNode = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextNode;
        }
        return pre;
    }
};

/*
题目：反转链表的[m, n]之间的元素
参考：LeetCode 92. Reverse Linked List II
例子：
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(n <= m) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        // pre为反转子链表的前一个结点
        for(int i = 0; i < m - 1; i++){
            pre = pre->next;
        }
        // 从pre->next开始反转，做n-m步。
        ListNode* first = pre->next;
        ListNode* second = first->next;
        for(int i = 0; i < (n - m); i++){
            ListNode* nextNode = second->next;
            second->next = first;
            first = second;
            second = nextNode;
        }
        pre->next->next = second;
        pre->next = first;
        return dummy->next;
    }
};

/*
题目：每k个结点反转一次链表，如果最后一段子链表长度不足k，让其保持原样。
参考：LeetCode 25. Reverse Nodes in k-Group
例子：
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1) return head;

        // 小技巧：添加一个辅助结点，使得第一个要反转的子链表也有前驱结点。
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // 定义两个指针分别指向要反转的list的首尾，这样list反转之后容易找到首尾
        // 还要定义一个指针指向这段list的前一个元素（cur）
        ListNode* cur = dummy;
        while(cur){
            head = cur->next;  // 指向这段子链表的头
            ListNode* tail = cur;  // 指向这段子链表的尾
            for(int i = 0; i < k; i++){
                tail = tail->next;
                if(tail == NULL) break;
            }
            if(tail == NULL) break;
            // 以下为反转[head, tail]这段子链表操作
            ListNode* first = head;
            ListNode* second = first->next;
            while(first != tail){
                ListNode* nextNode = second->next;
                second->next = first;
                first = second;
                second = nextNode;
            }
            cur->next = first;
            cur = head;
            cur->next = second;
        }
        return dummy->next;
    }
};