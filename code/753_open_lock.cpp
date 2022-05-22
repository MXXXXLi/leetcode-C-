class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        queue<string> que;
        unordered_set<string> deadset(deadends.begin(),deadends.end());
        if(deadset.count("0000")) return -1;
        unordered_map<string,int> visit;
        auto numnext = [](char x) {return x=='9'?'0':x+1;};
        auto numpre = [](char x) {return x=='0'?'9':x-1;};
        auto get = [&](string &status) {
            vector<string> ret;
            for(int i = 0;i < 4;i++){
                char n = status[i];
                status[i] = numnext(n);
                ret.push_back(status);
                status[i] = numpre(n);
                ret.push_back(status);
                status[i] = n;
            }
            return ret;
        };
        que.push("0000");
        visit["0000"] = 0;
        int step = 0;
        while(!que.empty()){
            string ss = que.front();
            if(visit.count(ss))
                step = visit[ss];
            que.pop();
            for(auto&& s:get(ss)){
                if(visit.count(s)||deadset.count(s))
                    continue;
                else{
                    if(target == s) return step+1;
                    visit[s] = step+1;
                    que.push(s);
                }
            };
        }
        return -1;
    }
};