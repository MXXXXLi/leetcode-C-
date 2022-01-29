class Solution {
public:
    map<int,int> helpMap;
    int numTrees(int n) {
        if(n <= 1) return 1;
        int ret = 0;
        for(int i = 1;i<n+1;++i)
        {
            int left = 1, right = 1;
            if(helpMap.find(i-1)!= helpMap.end())
                left = helpMap[i-1];
            else
                left = numTrees(i-1);
            if(helpMap.find(n-i) != helpMap.end())
                right = helpMap[n-i];
            else
                right = numTrees(n-i);
            ret += left*right;
        }
        helpMap.insert(make_pair(n,ret));
        return ret;
    }
};