class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* headA1 = headA;
        ListNode* headB1 = headB;
        bool reachEndA = false;
        bool reachEndB = false;
        while(headA1&&headB1){
            if(headA1 == headB1)
                return headA1;
            //cout<<headA1->val<<headB1->val<<endl;
            if(!headA1->next&&!reachEndA){
                headA1 = headB;
                reachEndA = true;
            }
            else
                headA1 = headA1->next;
            if(!headB1->next&&!reachEndB){
                headB1 = headA;
                reachEndB = true;
            }
            else
                headB1 = headB1->next;
        }
        return NULL;
    }
};