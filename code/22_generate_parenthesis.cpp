class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        string trail;
        backtrack(n,0,0,trail);
        return ret;
    }
    void backtrack(int n, int left, int right, string trail)
    {
        if(left==n && right == n)
        {
            ret.push_back(trail);
            return;
        }
        if(left<right)
            return;
        if(left>n || right>n)
            return;
        trail.push_back('(');
        backtrack(n, left + 1, right,trail);
        trail.pop_back();

        trail.push_back(')');
        backtrack(n, left, right + 1,trail);
        trail.pop_back();

    }
};
