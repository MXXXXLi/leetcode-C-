/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> hashmap;
        Node* cur = head;
        Node* pre = NULL;
        while(cur)
        {
            Node* copy = new Node(cur->val);
            hashmap[cur] = copy;
            if(pre){
                pre->next = copy;
            }
            pre = copy;
            cur = cur->next;
        }
        Node* cur1 = head;
        while(cur1)
        {
            Node* copyCur = hashmap[cur1];
            copyCur->random = hashmap[cur1->random];
            cur1=cur1->next;
        }
        return hashmap[head];
    }
};