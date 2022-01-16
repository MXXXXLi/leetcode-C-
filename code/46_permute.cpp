class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backTrack(nums,track);
        return ret;
    }
    void backTrack(vector<int>& nums,vector<int>&track)
    {
        if(track.size() == nums.size())
        {
            ret.push_back(track);
            return;
        }

        for(int i = 0;i<nums.size();i++)
        {
            if(std::find(track.begin(),track.end(),nums[i])!=track.end())
                continue;
            track.push_back(nums[i]);
            backTrack(nums,track);
            track.pop_back();
        }
    }
};
