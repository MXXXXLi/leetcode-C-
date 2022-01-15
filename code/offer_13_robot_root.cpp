class Solution {
public:
    int direc[4][2] = {{1,0},{0,1}};
    vector<vector<bool>> visit;
    int count;
    int movingCount(int m, int n, int k) {
        count = 0;
        visit = vector<vector<bool>>(m,vector<bool>(n,false));
        visit[0][0] = true;
        backtrack(m,n,k,0,0);
        return count;
    }
    void backtrack(int m, int n, int k, int row, int col)
    {
        int r = row, c = col;
        int sum = 0;
        while(r>0)
        {
            sum+=r%10;
            r = r/10;
        }
        while(c>0)
        {
            sum+=c%10;
            c = c/10;
        }
        if(sum<=k)
        {
            cout<<row<<" "<<col<<endl;
            count++;
        }else
            return;
        for(int i = 0; i < 2; ++i)
        {
            if((row+direc[i][0]>=m)||(col+direc[i][1]>=n)||(row+direc[i][0]<0)||(col+direc[i][1]<0))
                continue;
            if(visit[row+direc[i][0]][col+direc[i][1]])
                continue;
            visit[row+direc[i][0]][col+direc[i][1]] = true;
            backtrack(m,n,k,row+direc[i][0],col+direc[i][1]);
            //visit[row+direc[i][0]][col+direc[i][1]] = false;
        }
    }
};
