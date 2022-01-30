class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0;
        unordered_map<char,int> pMap;
        for(int i = 0;i<p.size();i++)
        {
            pMap[p[i]]++;
        }
        unordered_map<char,int> need;
        //int winSize = 0;
        int valid = 0;
        vector<int> ans;
        while(right < s.size())
        {
            need[s[right]]++;
            if(pMap.count(s[right])){
                if(need[s[right]] == pMap[s[right]])
                    valid++;
            }
            right++;
            while(right-left >= p.size())
            {
                if(valid == pMap.size()){
                    ans.push_back(left);
                }
                if(pMap.count(s[left]))
                {
                    if(pMap[s[left]] == need[s[left]])
                        valid--;
                    need[s[left]]--;
                }
                left++;
            }
        }
        return ans;
    }
};