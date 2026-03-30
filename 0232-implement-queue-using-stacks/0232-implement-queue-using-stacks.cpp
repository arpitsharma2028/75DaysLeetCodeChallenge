class MyQueue {
public:
    stack<int>s;
    int deleteBottom(stack<int> &s){
        if(s.empty())return-1;
        if(s.size() == 1){
            int temp = s.top();
            s.pop();
            return temp;
        }
        int temp = s.top();
        s.pop();
        int bottom = deleteBottom(s);
        s.push(temp);
        return bottom;    
    }
    int StackBottom(stack<int> &s){
        if(s.empty())return -1 ;
        if(s.size() == 1){
            return s.top();
        }
        int temp = s.top();
        s.pop();
        int bottom = StackBottom(s);
        s.push(temp);    
        return bottom;    
    }
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        return deleteBottom(s);
    }
    
    int peek() {
        return StackBottom(s);
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */