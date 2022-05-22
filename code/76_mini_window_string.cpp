class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tmap,smap;
        for(char ch:t){
            if(tmap.count(ch))
                tmap[ch]++;
            else
                tmap[ch] = 1;
        }
        int left = 0,right = 0;
        int count = 0;
        string ans;
        int min = s.size()+1;
        while(right<s.size()){
            char ch = s[right];
            right++;
            if(smap.count(ch))
                smap[ch]++;
            else
                smap[ch] = 1;
            if(tmap.count(ch)&&smap[ch] == tmap[ch]){
                count++;
            }
            if(count == tmap.size())
            {
                while(!tmap.count(s[left])||smap[s[left]]>tmap[s[left]]){
                    smap[s[left]]--;
                    left++;
                }
                if(right-left<min)
                {
                    ans = s.substr(left,right-left);
                    min = right- left;
                }
            }
        }
        return ans;
    }
};