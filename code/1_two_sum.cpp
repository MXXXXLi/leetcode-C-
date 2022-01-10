class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;//key:nums[i],value[i]
        vector<int> ret;
        for(int i = 0;i < nums.size();++i)
        {
            if(hashMap.find(target - nums[i])!=hashMap.end())
            {
                ret.push_back(i);
                ret.push_back(hashMap[target-nums[i]]);
            }
            hashMap[nums[i]] = i;
        }
        return ret;
    }
};