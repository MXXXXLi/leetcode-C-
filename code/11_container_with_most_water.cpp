class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = min(height[left],height[right])*(right - left);
        while(right > left)
        {
            if(height[right]>height[left]){
                int i = left+1;
                while(i<right&&height[i]<=height[left])
                {
                    i++;
                }
                left = i;
            }
            else{
                int j = right-1;
                while(j>left&&height[j]<=height[right])
                {
                    j--;
                }
                right = j;
            }
            maxArea = max(maxArea,(right-left)*min(height[left],height[right]));
        }
        return maxArea;
    }
};
