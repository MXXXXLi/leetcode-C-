class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        vector<vector<int>> ans;

        deque<TreeNode*> helpQue;
        helpQue.push_back(root);
        int count = 1;
        while(!helpQue.empty()){
            vector<int> eachLayer;
            int size = helpQue.size();
            cout<<size<<endl;
            for(int i = 0;i<size;i++){
                if(count%2 == 1){
                    TreeNode* node = helpQue.front();
                    helpQue.pop_front();
                    eachLayer.push_back(node->val);
                    if(node->left)helpQue.push_back(node->left);
                    if(node->right)helpQue.push_back(node->right);
                
                }else{
                    TreeNode* node = helpQue.back();
                    helpQue.pop_back();
                    eachLayer.push_back(node->val);
                    if(node->right)helpQue.push_front(node->right);
                    if(node->left)helpQue.push_front(node->left);
                }
            }
            count++;
            ans.push_back(eachLayer);
        }
        return ans;
    }
};
};