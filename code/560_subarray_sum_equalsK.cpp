class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        hashmap[0] = 1;
        int pre = 0;
        int count = 0;
        for(auto& n:nums){
            pre+=n;
            if(hashmap.find(pre-k)!=hashmap.end()){
                count += hashmap[pre-k];
            }
            hashmap[pre]++;
        }
        return count;
    }
};