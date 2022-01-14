class Solution {
public:
    int direc[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<bool>> visit;
    bool exist(vector<vector<char>>& board, string word) {
        visit = vector<vector<bool>>(board.size(),vector<bool>(board[0].size(),false));
        int m = board.size();
        int n = board[0].size();
        string temp;
        for(int i = 0;i<m;++i)
            for(int j = 0;j<n;++j){
                temp = board[i][j];
                visit[i][j] = true;
                if(backtrack(board,temp,word,i,j,m,n))
                    return true;
                visit[i][j] =false;
            }

        return false;
    }
    bool backtrack(vector<vector<char>>& board, string temp, string word,int row, int col,int m, int n){
        if(temp == word)
            return true;
        if(temp[temp.size()-1]!=word[temp.size()-1])
            return false;
        for(int i = 0;i<4;++i)
        {
            int row1 = row+diraec[i][0];
            int col1 = col+direc[i][1];
            if(row1 < 0 || row1 >= m ||col1 < 0 || col1 >= n || visit[row1][col1])
                continue;
            temp= temp + board[row1][col1];
            visit[row1][col1] = true;
            if(backtrack(board,temp,word,row1,col1,m,n))
                return true;
            temp= temp.substr(0,temp.size()-1);
            visit[row1][col1] = false;
        }
        return false;
    }
};
