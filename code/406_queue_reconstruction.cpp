class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//先排序，如果身高相同，前面空位多的在前面
        sort(people.begin(),people.end(),[](vector<int>& f,vector<int>& e){return f[0]<e[0]||(f[0] == e[0]&&f[1]>e[1]);});
        int n = people.size();
        vector<vector<int>> ans(n);
//再插入，只有排在后面的人对kj有影响
        for(int i = 0;i < n;++i)
        {
            int spaceLeft = 0;
            for(int j = 0; j<n;++j)
            {
                if(ans[j].empty())
                    spaceLeft++;
                if(spaceLeft == people[i][1]+1){
                    ans[j] = people[i];
                    break;
                }
            }
        }
        return ans;

    }
};