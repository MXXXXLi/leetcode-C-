class Solution {
public:
    vector<vector<bool>> isVisit;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        isVisit = vector<vector<bool>>(grid.size(),vector<bool>(grid[0].size(),false));
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(helpVisit(grid,i,j))
                    ans++;
            }
        }
        return ans;
    }
    bool helpVisit(vector<vector<char>>& grid, int r, int c){
        if(!isVisit[r][c]&&grid[r][c] == '1'){
            isVisit[r][c] = true;
            if(r+1<grid.size()) helpVisit(grid,r+1,c);
            if(c+1<grid[0].size()) helpVisit(grid,r,c+1);
            if(r-1>-1) helpVisit(grid,r-1,c);
            if(c-1>-1) helpVisit(grid,r,c-1);
            return true;
        }else{
            return false;
        }
    }
};