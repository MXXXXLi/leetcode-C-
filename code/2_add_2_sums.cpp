class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* ansptr = ans;
        ListNode* l1ptr = l1;
        ListNode* l2ptr = l2;
        int upward = 0;
        while(l1ptr != nullptr || l2ptr != nullptr)
        {
            ansptr->next = new ListNode();
            ansptr = ansptr->next;
            if(l1ptr == nullptr){
                ansptr->val = (l2ptr->val+upward)%10;
                upward = (l2ptr->val+upward)/10;
                l2ptr = l2ptr->next;
            }
            else if(l2ptr == nullptr){
                ansptr->val = (l1ptr->val+upward)%10;
                upward = (l1ptr->val+upward)/10;
                l1ptr = l1ptr->next;
            }
            else{
                ansptr->val = (l1ptr->val+l2ptr->val+upward)%10;
                upward = (l1ptr->val+l2ptr->val+upward)/10;
                l2ptr = l2ptr->next;
                l1ptr = l1ptr->next;

            }
        }
        if(upward!=0){
             ansptr->next = new ListNode();
             ansptr = ansptr->next;
             ansptr->val = upward;
        }

        return ans->next;
    }
};
