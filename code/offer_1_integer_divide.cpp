class Solution {
public:
    int divide(int a, int b) {
        if(a == -2147483648&&b == -1) return 2147483647;
        int sign = ((a>0&&b>0)||(a<0&&b<0))?1:-1;
        a = a>0?0-a:a;
        b = b>0?0-b:b;
        unsigned ans=0;
        while(a<=b){
            long minusValue = b;
            int times = 1;
            while(minusValue+minusValue>=a&&minusValue>-1073741824){
                cout<<times<<" "<<minusValue<<endl;
                minusValue+=minusValue;
                times+=times;
            }
            a = a-minusValue;
            ans=ans+times;
        }
        return (sign==1)?ans:0-ans;
    }
};
