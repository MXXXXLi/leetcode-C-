class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1, right = 1;
        vector<vector<int>> ans;
        int tmpSum = 0;
        while(right<(target/2+3)){
            if(tmpSum == target){
                vector<int> tmp;
                for(int i = left;i<right;i++){
                    tmp.push_back(i);
                }
                ans.push_back(tmp);
            }
            tmpSum+=right;
            right++;
            while(tmpSum>target&&left<right){
                tmpSum -= left;
                left++;
            }
        }
        return ans;
    }
};