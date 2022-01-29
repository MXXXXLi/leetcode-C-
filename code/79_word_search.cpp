class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0)
            return false;
        vector<vector<bool>> isvisit(board.size(),vector<bool>(board[0].size(),false));
        for(int i = 0;i<board.size();i++)
            for(int j = 0;j<board[0].size();j++){
                isvisit[i][j] = true;
                if(backtrack(board,isvisit,word,0,i,j))
                    return true;
                isvisit[i][j] = false;
                }

        return false;
    }
    bool backtrack(vector<vector<char>>& board,vector<vector<bool>>& isvisit,string& word,int u,int r,int c)
    {
        if(word[u]!=board[r][c])
            return false;
        if(u == word.size()-1)
            return true;
        if(c+1<board[0].size())
        {
            if(!isvisit[r][c+1]){
                isvisit[r][c+1] = true;
                bool isFind = backtrack(board,isvisit,word,u+1,r,c+1);
                if(isFind) 
                    return true;
                else
                {
                    isvisit[r][c+1] = false;
                }
            }
        }
        if(c-1>=0)
        {
           if(!isvisit[r][c-1]){
                isvisit[r][c-1] = true;
                bool isFind = backtrack(board,isvisit,word,u+1,r,c-1);
                if(isFind)
                    return true;
                else
                {
                    isvisit[r][c-1] = false;
                }
            }
        }
        if(r+1<board.size())
        {
            if(!isvisit[r+1][c]){
                isvisit[r+1][c] = true;
                bool isFind = backtrack(board,isvisit,word,u+1,r+1,c);
                if(isFind) 
                    return true;
                else
                {
                    isvisit[r+1][c] = false;
                }
            }
        }
        if(r-1>=0)
        {
            if(!isvisit[r-1][c]){
                isvisit[r-1][c] = true;
                bool isFind = backtrack(board,isvisit,word,u+1,r-1,c);
                if(isFind)
                    return true;
                else
                {
                    isvisit[r-1][c] = false;
                }
            }
        }
        //track.pop_back();
        //isvisit[r][c] = false;
        return false;
    }
};