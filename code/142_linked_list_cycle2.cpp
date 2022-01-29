/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *help = head;
        while(fast != nullptr)
        {
            //cout<<fast->val;
            fast = fast->next;
            if(fast)
                fast = fast->next;
            else
                return nullptr;
            slow = slow->next;
            if(fast == slow)
            {
                //cout<<fast->val;
                while(help!=slow)
                {
                    help = help->next;
                    slow = slow->next;
                }
                if(help == slow)
                    return help;
            }
        }
        return nullptr;
    }
};