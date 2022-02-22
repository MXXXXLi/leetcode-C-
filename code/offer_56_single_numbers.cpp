class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        //利用异或的性质，两数相同为0，不同为1；注意指的是位运算，两个十进制数字异或会得到一个不为0的数，
        //这意味着这个数字如果转换为二进制一定有一位不为0，那么就可以利用这一位将两个数字分到两个不同的组，
        //即a&m ==0 ;b&m!=0;
        //数组中其他的数字中相同的两个数字也会被分到同一组
		
        //首先计算异或结果
        int n = 0, m = 1;
        int x = 0, y = 0;
        for(auto num:nums){
            n^=num;
        }
        while(!(m&n)){
            //cout<<m<<endl;
            m<<=1;
        }
        
		//利用不为0的那一位（m表示）来分组
        for(int num:nums){
            if(num&m)
                x^=num;
            else
                y^=num;

        }
        return vector<int>{x,y};
    }
};