class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> num;
        int index1 = 0,index2 = 0;
        while(index1<nums1.size()&&index2<nums2.size())
        {
            if(nums1[index1]<nums2[index2]){
                num.push_back(nums1[index1]);
                index1++;
            }
            else
            {
                num.push_back(nums2[index2]);
                index2++;
            }
        }
        if(index1 == nums1.size())
            for(int j = index2;j<nums2.size();++j)
                num.push_back(nums2[j]);
        else
            for(int j = index1;j<nums1.size();++j)
                num.push_back(nums1[j]);

        int lenAll = nums1.size()+nums2.size();
        //cout<<num[lenAll/2-1]<<num[lenAll/2];
        if(lenAll%2 == 1)
            return num[lenAll/2];
        else
            return (num[lenAll/2-1]+num[lenAll/2])/2;
    }
};
