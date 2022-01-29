class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() == 0) return true;
        return help(postorder,0,postorder.size()-1);
    }
    bool help(vector<int>& postorder,int start, int end)
    {
        if(start == end) return true;
        int root = postorder[end];
        int borderIndex = -1;
        for(int i = start;i<end;i++)
        {
            if(postorder[i]>root&&borderIndex == -1)
            {
                borderIndex = i;
                break;
            }
        }
        for(int i = borderIndex+1;i<end;i++)
        {
            if(borderIndex>=0&&postorder[i]<root){        
                return false;
            }
        }
        if(borderIndex>start)
            return help(postorder,start,borderIndex-1)&&help(postorder,borderIndex,end-1);
        else if(borderIndex == start)
            return help(postorder,borderIndex,end-1);
        else{
            return help(postorder,start,end-1);
        }
    }
};