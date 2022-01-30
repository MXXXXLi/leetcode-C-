class Solution {
public:
    vector<bool> visit;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mapString2Num;
        //vector<vector<int>> adjentTbl;
        int num = 0;
        //用数字表示字符串，建立对应关系
        for(int i = 0;i<equations.size();++i)
        {
            if(mapString2Num.count(equations[i][0]) == 0)
                mapString2Num[equations[i][0]] = num++;
            if(mapString2Num.count(equations[i][1]) == 0)
                mapString2Num[equations[i][1]] = num++;
        }
        //构建邻接表
        vector<vector<int>> adjentTbl(num);
        for(int i = 0;i<equations.size();++i)
        {
            adjentTbl[mapString2Num[equations[i][0]]].push_back(mapString2Num[equations[i][1]]);
            adjentTbl[mapString2Num[equations[i][1]]].push_back(mapString2Num[equations[i][0]]);
        }
        //构建权重表
        vector<vector<double>> weightTbl(num);
        for(int i = 0;i<equations.size();++i)
        {
            weightTbl[mapString2Num[equations[i][0]]].push_back(values[i]);
            weightTbl[mapString2Num[equations[i][1]]].push_back(1/values[i]);
        }
        vector<double> ans(queries.size(),-1);
        visit = vector<bool>(num,false);
        for(int i = 0;i<queries.size();i++)
        {
            if(mapString2Num.count(queries[i][0])!=0&&mapString2Num.count(queries[i][1])!=0)
            {
                int begin = mapString2Num[queries[i][0]];
                int end = mapString2Num[queries[i][1]];
                double ret = 1;
                traverse(adjentTbl,weightTbl,begin,end,ret,i,ans);
            }

        }
        return ans;
    }
    void traverse(vector<vector<int>>& adjentTbl, vector<vector<double>>& weightTbl,int begin,int end, double res, int a, vector<double>& ans)
    {
        if(begin == end){
            ans[a] = res;
            return;
        }
        if(visit[begin])
            return;
        visit[begin] = true;
        for(int i = 0;i<adjentTbl[begin].size();i++)
        {
            res*=weightTbl[begin][i];
            traverse(adjentTbl,weightTbl,adjentTbl[begin][i],end,res,a,ans);
            res/=weightTbl[begin][i];
        }
        visit[begin] = false;
        return;
    }
};