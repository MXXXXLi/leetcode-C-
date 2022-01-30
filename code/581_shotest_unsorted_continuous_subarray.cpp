class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       vector<int> origiNums = nums;
       sort(nums.begin(),nums.end());
       int n = nums.size();
       int beginPos = n+1;
       for(int i = 0;i<n;i++)
       {
           if(nums[i]!=origiNums[i]){
                beginPos = i;
                break;
           }
       }
       if (beginPos == n+1)
            return 0;
        int endPos = n+1;
       for(int i = n-1;i>-1;i--)
       {
           if(nums[i]!=origiNums[i]){
                endPos = i;
                break;
           }
       }
       return endPos - beginPos+1;
    }
};