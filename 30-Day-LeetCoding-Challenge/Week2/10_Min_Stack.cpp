class MinStack {
private:
    stack<int> minStack;
    stack<int> stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push(x);
        if(minStack.empty() || x <= minStack.top()) {
           minStack.push(x);            
        }     
    }
    
    void pop() {
        if(minStack.top() == stack.top() )
            minStack.pop();
        stack.pop();        
    }
    
    int top() {
        return stack.top();        
    }
    
    int getMin() {
        return minStack.top();        
    }
};