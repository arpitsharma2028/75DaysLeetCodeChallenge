class MinStack {
private:
    stack<long long int>s;
     long long int minVal = INT_MAX;
    /*
    if(curr < minVal)
    val = 2*curr - minVal;

    then update minVal = curr;

    minVal is basically old min value and curr is new min value and val is just a val variable
    which create a realtion between new min and old min so we can revert back to our previous value of min

    or in else case if above condition is not true then we do normal push and pop operation
    */
         
public:
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            minVal = x;
        }
        else{
        if(x < minVal){
            s.push((long long) 2*x - minVal);
            minVal = x;
        }
        else s.push(x);
        }
    }
    
    void pop() {
        if(s.top() < minVal){
            minVal = (long long )2*minVal - s.top();
        }
        s.pop();

    }
    
    int top() {
        if(s.top() < minVal){
            return minVal;
        }
        else return s.top();
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */