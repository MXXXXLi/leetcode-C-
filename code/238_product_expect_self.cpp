class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int>answer(length,1);
        //先用answer保存左侧数字乘积
        for(int i = 1;i<length;i++){
            answer[i] = answer[i-1]*nums[i-1];
        }

        int R = 1;//R表示右侧数字成绩
        for(int i = length-1;i>=0;i--){
            answer[i] = answer[i]*R;
            R = R* nums[i];
        }
        return answer;
    }
};