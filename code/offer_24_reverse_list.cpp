class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* child = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return child;
    }
};