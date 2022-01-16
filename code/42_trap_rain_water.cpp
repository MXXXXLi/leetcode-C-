class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3) return 0;
        int area = 0;
        int first = 0,second = 0;
        int shadeArea = 0;
        bool isLow = false;
        while(second < n-1){
            cout<<first<<" "<<second<<" "<<area<<endl;
            if(!isLow)
            {
                if(height[second] <= height[second+1]){//second 和first同步
                    first++;
                    second++;
                }else{
                    isLow = true;
                }
            }
            if(isLow){
                shadeArea+=height[second];
                second++;
                if(height[second]>=height[first])
                {
                    area+= (second-first)*height[first]-shadeArea;
                    first = second;
                    isLow = false;
                    shadeArea = 0;
                }
            }
        }
        if(height[first]>height[second]){
        for(int i = first+1;i<second;++i)
        {
            area+=(height[second]>height[i])?(height[second]-height[i]):0;
        }}
        return area;
    }
};
