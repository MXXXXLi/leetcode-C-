/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(!root) return "o";
        ans+= std::to_string(root->val);
        string left = serialize(root->left);
        if(!left.empty())
        {
            ans+=",";
            ans+=left;
        }
        string right = serialize(root->right);
        if(!right.empty())
        {
            ans+=",";
            ans+=right;
        }
        //cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> array;
        string ch;
        for(auto c:data)
        {
            if(c == ','){
                array.push_back(ch);
                //cout<<ch<<endl;
                ch = "";
                continue;
            }
            ch.push_back(c);
        }
        if(!ch.empty())
            array.push_back(ch);
        return deserialize1(array);
    }
    TreeNode* deserialize1(list<string>& array) {
        string str = array.front();
        if(str == "o")
        {
            array.erase(array.begin());
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(str));
        array.erase(array.begin());
        root->left = deserialize1(array);
        root->right = deserialize1(array);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));