class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> helps;
        vector<int> ans(temperatures.size(),0);
        for(int i = 0;i<temperatures.size();++i){
            if(helps.empty()||temperatures[i]<=temperatures[helps.top()]){
                helps.push(i);
            }
            if(temperatures[i]>temperatures[helps.top()]){
                while(!helps.empty()&&temperatures[i]>temperatures[helps.top()]){
                    int temp = helps.top();
                    ans[temp] = i-temp;
                    helps.pop();
                }
                helps.push(i);
            }
            
        }
        return ans;
    }
};