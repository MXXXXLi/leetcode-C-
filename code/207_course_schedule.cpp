//深度优先搜索
class Solution {
public:
    vector<int>visit;
    bool dfs(int v,vector<vector<int>>& g)
    {
        if (g[v].size() == 0)   //没相邻的节点了，返回true
            return true;
       
        if (visit[v] == -1)   //走这节点没环，返回true
            return true;
        
        if (visit[v] == 1)  //被标记过了，存在环，返回false
            return false;

        visit[v] = 1;  //标记

        bool res = true;
        for (int i = 0; i < g[v].size(); i++)  //访问v节点的所有相连接的节点，对于每个节点都进行dfs
        {
            res = dfs(g[v][i], g);
            if (res == false)
                break;
        }
        visit[v] =-1 ;  //回溯时设置visit为-1
        return res;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        visit = vector<int>(numCourses + 1, 0);
        //建立有向邻接表
        for (int i = 0; i < prerequisites.size(); i++)
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);

        bool res = true;
          for(int i =0;i<numCourses;i++)  //对每个节的所有相连接的点进行dfs（深度优先遍历）
            for (int j = 0; j < g[i].size(); j++)
            {
                 res = dfs(g[i][j], g);
                 if (res == false)
                     return res;
            }
        return res;
    }
};
//拓扑排序
class Solution1 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adjacentTbl(numCourses,vector<int>());
        for(auto v:prerequisites)
        {
            adjacentTbl[v[1]].push_back(v[0]);//构建邻接表
            inDegree[v[0]]++;//构建入度表
        }
        queue<int> que;
        for(int i = 0;i<numCourses;i++)
        {
            if(inDegree[i] == 0)
                que.push(i);
        }
        int count = 0;//表示已经学的课程数量
        
        while(que.size())
        {
            int a = que.front();
            que.pop();
            count++;
            vector<int>& rely = adjacentTbl[a];
            for(auto b:rely)
            {
                cout<<b<<endl;
                if(--inDegree[b]==0)
                {
                    que.push(b);
                }
            }
        }
        return count==numCourses;
    }
};