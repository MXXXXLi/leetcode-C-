/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helpBuildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* helpBuildTree(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight)
    {
        if(preLeft > preRight)
            return nullptr;
        //if(preLeft == preRight){
            //TreeNode* node = new TreeNode(preorder[preLeft]);
            //return node;
        //}
        int index = 0;
        for (int i = inLeft;i<=inRight;++i)
        {
            if(inorder[i] == preorder[preLeft]){
                index = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(preorder[preLeft]);
        TreeNode* left = helpBuildTree(preorder, preLeft+1,preLeft+index-inLeft,inorder,inLeft,index-1);
        TreeNode* right = helpBuildTree(preorder,preLeft+1+index-inLeft,preRight,inorder,index+1,inRight);
        root->left = left;
        root->right = right;
        return root;
    }
};