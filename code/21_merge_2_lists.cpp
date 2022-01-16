/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* nPtr = head;
        while(nPtr)
        {
            count++;
            nPtr = nPtr->next;
        }
        if(count == n)
        {
            return head->next;
        }
        nPtr = head;
        int i = 0;
        while(i < (count - n - 1))
        {
            i++;
            nPtr = nPtr->next;
        }
        ListNode* dele = nPtr->next;
        nPtr->next = dele->next;
        delete dele;
        return head;
    }
};
