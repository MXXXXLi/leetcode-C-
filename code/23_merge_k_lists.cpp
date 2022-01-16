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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* preHead = new ListNode(-1);
        ListNode* cur = preHead;
        while(1){
            int minVal = 10001;
            int seIndex = -1;
            bool hasNode = false;
            for(int i = 0;i<lists.size();++i)
            {
                if(lists[i])
                {
                    hasNode = true;
                    if(lists[i]->val < minVal)
                    {
                        minVal = lists[i]->val;
                        seIndex = i;
                    }
                }
            }
            if(!hasNode)
                break;
            if(seIndex != -1){
                cur->next = lists[seIndex];
                lists[seIndex] = lists[seIndex]->next;
                cur = cur->next;
            }
        }
        return preHead->next;
    }
};
