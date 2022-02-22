class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0;
        vector<string> strVec;
        s.push_back(' ');
        while(right<s.size()){
            while(s[right] == ' '&&s[left] == ' ')
            {
                right++;
                left++;
            }
            if(s[right] == ' '){
                strVec.push_back(s.substr(left,right-left));
                while(s[right] == ' ')
                {
                    right++;
                }
                left = right;
            }
            else
                right++;
        }
        string ans;
        for(int i = strVec.size()-1;i>=0;i--){
            ans+=strVec[i];
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};