class Solution {
public:
    vector<string> retV;
    int minNum;
    vector<string> removeInvalidParentheses(string s) {      
        string track;
        int left = 0,right = 0;
        for(int i = 0;i<s.size();i++)
        {
            char o = s[i];
            if(s[i] == '('){
                left++;
            }
            else if(s[i] == ')'){
                if(left == 0)
                    right++;
                else
                    left --;
            }
        }
        if(left == 0 &&right == 0)
        {
            retV.push_back(s);
            return retV;
        }
        backtrack(s,0,left,right);
        return retV;
    }
    void backtrack(string s, int u,int left,int right)
    {

        if(isValid(s)&&(left==0)&&(right == 0)){
            //ret.insert(s);
            retV.push_back(s);
            return;
        }    
        for(int i = u; i < s.length(); i ++) {
            // 忽略重复
            if(i > 0 && s[i] == s[i - 1]) continue;
            // 删除左括号
            if(left > 0 && s[i] == '(') {
                backtrack(s.substr(0, i) + s.substr(i + 1, s.length() - i - 1), i, left - 1, right);
            }
            // 删除右括号
            if(right > 0 && s[i] == ')') {
                backtrack(s.substr(0, i) + s.substr(i + 1, s.length() - i - 1), i, left, right - 1);
            }
        }
    }
    bool isValid(string s)
    {
        int right = 0,left = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(') 
                left++;
            else if(s[i] == ')') 
                right++;
            else
                continue;
            if(left<right)
                return false;
        }
        if (left == right) 
            return true;
        else 
            return false;
    }
};