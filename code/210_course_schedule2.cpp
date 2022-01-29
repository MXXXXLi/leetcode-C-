class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //建立各个节点的入度表,构建邻接表
        //unordered_map<int,int> inMap;
        vector<int> inVec(numCourses,0);
        vector<vector<int>> adjentTbl(numCourses);
        for(int i = 0;i<prerequisites.size();++i)
        {
            inVec[prerequisites[i][0]]++;
            adjentTbl[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ret;
        queue<int> helpQue;

        for(int i = 0;i<inVec.size();i++)
        {
            if(inVec[i] == 0)
            {
                helpQue.push(i);
            }  
        }
        while(!helpQue.empty())
        {
            int ele = helpQue.front();
            helpQue.pop();
            ret.push_back(ele);
           // cout<<ele<<endl;
            for(int j = 0;j<adjentTbl[ele].size();++j)
            {
                inVec[adjentTbl[ele][j]]--;
                if(inVec[adjentTbl[ele][j]] == 0)
                    helpQue.push(adjentTbl[ele][j]);
            }
        }
        if(ret.size() != numCourses)
            return {};
        else
            return ret;

    }
};