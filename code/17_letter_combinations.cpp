class Solution {
public:
    vector<string> ret;
    vector<string> record = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return ret;
        string track;
        backtrack(digits,track,0);
        return ret;
    }
    void backtrack(string digits,string track,int u)
    {
        if(track.size() == digits.size())
        {
            ret.push_back(track);
            return;
        }
        int index = digits[u] - '2';
        for(auto i:record[index]){
            track.push_back(i);
            backtrack(digits,track,u+1);
            track.pop_back();
        }
    }
};
