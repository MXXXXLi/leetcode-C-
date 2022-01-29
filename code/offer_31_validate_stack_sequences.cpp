class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> helpStack;
        int popIndex = 0;
        int pushIndex = 0;
        while(popIndex<pushed.size()&&pushIndex<pushed.size())
        {
            if(!helpStack.empty()&&popped[popIndex] == helpStack.top())
            {
                helpStack.pop();
                popIndex++;
            }
            else if(pushed[pushIndex] == popped[popIndex])
            {
                popIndex++;
                pushIndex++;
                continue;
            }
            else{
                helpStack.push(pushed[pushIndex]);
                pushIndex++;
            }
        }
        while(!helpStack.empty()){
            if(helpStack.top() == popped[popIndex])
            {
                helpStack.pop();
                popIndex++;
            }
            else
                return false;
        }
        return true;
    }
};
