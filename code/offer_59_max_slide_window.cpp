class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return vector<int>();
        deque<int> dque;//单调队列，里面的数据由大到小排列，随着窗口的滑动进行更新
        //里面的第一个数据永远是窗口内的最大值，后面的数据是排列必须是排列在最大值后面的数据
        int l = 1-k , r = 0;
        vector<int> ans;
        while(r < nums.size()){
            if(!dque.empty()&&l>0&&nums[l-1] == dque.front())
                dque.pop_front();
            while(!dque.empty()&&nums[r]>dque.back())
                dque.pop_back();
            dque.push_back(nums[r]);
            if(l>=0)
                ans.push_back(dque.front());
            l++;
            r++;

        }
        return ans;
    }
};