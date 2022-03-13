class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> a,pair<int,int> b){
            return a.second > b.second;//小顶堆是大于号
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cmap;
        for(auto &n:nums){
            cmap[n]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> que;
        for(auto &pair:cmap){
            que.push(pair);
            if(que.size()>k){
                que.pop();
            }
        }
        vector<int> ans;
        while(!que.empty()){
            ans.emplace_back(que.top().first);
            que.pop();
        }
        return ans;
    }
};