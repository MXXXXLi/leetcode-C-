class UnionFind {
    vector<int>parent;
public:
    UnionFind(int size){
        parent = vector<int>(size);
        for(int i = 0;i<size;i++){
            parent[i] = i;
        }
    }
    void union2Node(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ)
            return;
        parent[rootP] = rootQ;
    }

    int find(int p ){
        while(parent[p] != p){
            parent[p] = parent[parent[p]];//用来降低树的高度，减少迭代次数
            p = parent[p];
        }
        return p;
    }
    bool isConnect(int p, int q){
        return find(p) == find(q);
    }
};
class Solution {
public:
    vector<vector<int>> direc;
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        direc = {{1,0},{-1,0},{0,1},{0,-1}};
        int m = board.size();
        int n = board[0].size();
        UnionFind unin(m*n+1);
        //UnionFind *p = new UnionFind(m*n+1);
        int outter = m*n;
        for(int i = 0;i<m;i++){
            if(board[i][0] == 'O')
            {
                unin.union2Node(i*n,outter);
            }
            if(board[i][n-1] == 'O')
            {
                unin.union2Node(i*n+n-1,outter);
            }
        }
        for(int j = 0;j<n;j++){
            if(board[0][j] == 'O')
                unin.union2Node(j,outter);
            if(board[m-1][j] == 'O')
                unin.union2Node((m-1)*n+j,outter);
        }
        for(int i = 1;i<m-1;i++){
            for(int j = 1;j<n-1;j++){
                if(board[i][j] == 'O'){
                    for(auto di:direc)
                        if(board[i+di[0]][j+di[1]] == 'O'){
                            //cout<<i*n+j<<endl;
                            unin.union2Node((i+di[0])*n+j+di[1],i*n+j);
                        }
                    
                }
            }
        }
        for(int i = 0;i<m-1;i++){
            for(int j = 0;j<n-1;j++){
                if(!unin.isConnect(outter,i*n+j)){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};