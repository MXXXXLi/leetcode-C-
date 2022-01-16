class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> sMap;
        int left = 0,right = 0;
        int maxLen = 0;
        while(right < s.size())
        {
            char ss = s[right];
            right++;
            if(sMap.count(ss)&&sMap[ss]>0){
                sMap[ss]++;
            }
            else{
                sMap[ss] = 1;
                maxLen = max(maxLen,right-left);
            }
            while(sMap[ss]>1&&left<right)
            {
                char ll = s[left];
                if(sMap.count(ll)){
                    sMap[ll]--;
                }
                left++;
            }
        }
        return maxLen;
    }
};
