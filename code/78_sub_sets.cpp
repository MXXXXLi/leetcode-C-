class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backTrack(nums,track,0);
        return ret;
    }
    void backTrack(vector<int>& nums,vector<int>& track,int u)
    {
        if(u>nums.size())
            return;
        ret.push_back(track);
        for(int i = u;i<nums.size();i++)
        {
            track.push_back(nums[i]);
            backTrack(nums,track,i+1);
            track.pop_back();
        }
    }
};
