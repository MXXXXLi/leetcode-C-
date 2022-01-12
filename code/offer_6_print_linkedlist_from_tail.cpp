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
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        reverse(head);
        return res;
    }
    void reverse(ListNode* node)
    {
        if(!node) return;
        else
        {
            reverse(node->next);
            res.push_back(node->val);
        }
        return;
    }
};