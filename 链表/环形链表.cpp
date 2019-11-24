// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 给定一个链表，判断链表中是否有环。
class Solution {
   public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        bool circle = false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                circle = true;
                break;
            }
        }
        if (!circle) return nullptr;
        ListNode* slow2 = head;
        while (slow != slow2) {
            slow = slow->next;
            slow2 = slow2->next;
        }
        return slow;
    }
};