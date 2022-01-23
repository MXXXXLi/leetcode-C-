class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            //cout<<pre->val<<endl;
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        //cout<<pre->val<<endl;
        return pre;
    }
};
