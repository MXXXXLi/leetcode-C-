class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    void push(int x) {
        stack1.push(x);
        if(helpStack.empty()||x <= helpStack.top())
            helpStack.push(x);
    }
    void pop() {
        //cout<<stack1.top()<<endl;
        if(stack1.top() == helpStack.top())
            helpStack.pop();
        stack1.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return helpStack.top();
    }
    stack<int> helpStack;
    stack<int> stack1;
};
