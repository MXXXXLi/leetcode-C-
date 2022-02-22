class MaxQueue {
public:
    MaxQueue() {
    }
    
    int max_value() {
        if(helpQ.empty()) return -1;
        return helpQ.front();
    }
    
    void push_back(int value) {
        if(helpQ.empty()) 
            helpQ.push_back(value);
        else{
            while(!helpQ.empty()&&value >= helpQ.back())
            {
                helpQ.pop_back();
            }
            helpQ.push_back(value);
        }
        Q.push(value);
    }
    
    int pop_front() {
        if(Q.empty()) return -1;
        if(Q.front() == helpQ.front())
            helpQ.pop_front();
        int ret = Q.front();
        Q.pop();
        return ret;
    }

    queue<int> Q;
    deque<int> helpQ;//单调队列
    
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */