class MedianFinder {
public:
    priority_queue<int,vector<int>,less<int>> maxheap;//大顶堆存小的一半的值
    priority_queue<int,vector<int>,greater<int>> minheap;//小顶堆存大的一半的值
    MedianFinder() 
    {
    }
    void addNum(int num) 
    {
        if(maxheap.size()==minheap.size())//两堆元素相等优先加到小顶堆
        {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();//为什么不直接加，是要保证小顶堆的最小值要大于大顶堆的最大值
        }
        else if(maxheap.size()>minheap.size())
        {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();//为什么不直接加，是要保证小顶堆的最小值要大于大顶堆的最大值
        }
        else if(maxheap.size()<minheap.size())
        {
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();//为什么不直接加，是要保证小顶堆的最小值要大于大顶堆的最大值
        }
    }
    
    double findMedian() 
    {
        if(maxheap.size()==minheap.size())
        {
            return (maxheap.top()+minheap.top())/2.0;
        }
        else if(maxheap.size()>minheap.size())
        {
            return maxheap.top()/1.0;
        }
        else if(maxheap.size()<minheap.size())
        {
            return minheap.top()/1.0;
        }
        return 0;
    }
};