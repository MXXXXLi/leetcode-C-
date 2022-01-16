class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>track;
        backtrack(candidates,target,track,0,0);
        return ret;
    }
    void backtrack(vector<int>& candidates,int target,vector<int>&track,int sum,int u)
    {
        if(sum == target)
        {
            ret.push_back(track);
            return;
        }
        if(sum>target)
            return;
        for(int i = u;i<candidates.size();i++)
        {
            track.push_back(candidates[i]);
            sum+=candidates[i];
            backtrack(candidates,target,track,sum,i);
            int last = track.back();
            track.pop_back();
            sum -= last;
        }
    }
};
