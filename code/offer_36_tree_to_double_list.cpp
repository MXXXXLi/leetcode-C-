class Solution {
public:
    Node* head;
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return NULL;
        vector<Node*> ans = treeToList(root);
        ans[0]->left = ans[1];
        ans[1]->right = ans[0];
        return ans[0];

    }
    vector<Node*> treeToList(Node* root)
    {
        if(!root->left&&!root->right)
        {
            vector<Node*> ans;
            ans.push_back(root);
            ans.push_back(root);
            return ans;
        }
        vector<Node*> ans;
        Node* leftTail = NULL;
        if(root->left){
            vector<Node*> leftans = treeToList(root->left);
            leftTail = leftans[1];
            ans.push_back(leftans[0]);
        }
        else
            ans.push_back(root);
        if(leftTail){
            leftTail->right = root;
            root->left = leftTail;
        }
        Node* rightHead = NULL;
        if(root->right){
            vector<Node*> rightans = treeToList(root->right);
            rightHead = rightans[0];
            ans.push_back(rightans[1]);
        }
        else
            ans.push_back(root);
        if(rightHead){
            root->right = rightHead;
            rightHead->left = root;
        }
        return ans;       
    }
};