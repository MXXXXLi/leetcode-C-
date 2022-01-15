class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        int second = 0,third = 0;
        vector<int> ret(3);
        for(int i = 0;i < n-2;i++)
        {
            second = i+1;
            third = n-1;
            if(i>0&&nums[i] == nums[i-1])//去重
                continue;
            while(third>second){
                ret.clear();
                if((nums[i]+nums[second]+nums[third])>0){
                    third --;
                }
                else if((nums[i]+nums[second]+nums[third])<0){
                    second++;
                }
                else
                {
                    ret.push_back(nums[i]);
                    ret.push_back(nums[second]);
                    ret.push_back(nums[third]);
                    ans.push_back(ret);
                    while(second<third&&nums[second] == nums[second+1])//去重
                        second++;
                    while(second<third&&nums[third] == nums[third-1])//去重
                        third--;
                    second++;
                    third--;
                }
            }
        }
        return ans;
    }
};
