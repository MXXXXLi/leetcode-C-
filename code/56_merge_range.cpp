class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(auto pair:intervals){
            if(pair[0]<=ans[ans.size()-1][1])
                ans[ans.size()-1][1] = max(pair[1],ans[ans.size()-1][1]);
            else
                ans.push_back(pair);
        }
        return ans;
    }
};