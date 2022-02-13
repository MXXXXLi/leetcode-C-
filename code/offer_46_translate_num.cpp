class Solution {
public:
    int translateNum(int num) {
        //计算num多少位
        int count = 1;
        while(num/long(pow(10,count)) > 0){
            count++;
        }
        if(count == 1) return 1;
        if(count == 2) {
            if(num<26)
                return 2;
            else
                return 1;
        }
        int prepre = 1;//第一个数只可能有一种
        int pre;
        if(num/long(pow(10,count-2))<26)
            pre = 2;
        else
            pre = 1;
        for(int i = 3;i<=count;i++)
        {
            int douNum = num/long(pow(10,count-i))%100;
            if(douNum<26&&douNum>9){
                int cur = prepre+pre;
                prepre = pre;
                pre = cur;  
            }
            else{
                prepre = pre;
            }
        }
        return pre;
    }
};