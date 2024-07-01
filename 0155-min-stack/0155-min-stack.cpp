class MinStack {
public:
    stack<long long> s;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push(0);
            mini = val;
        } else {
            s.push(val - mini); // Could be negative if val is smaller than mini
            if (val < mini) {
                mini = val;
            }
        }
    }
    
    void pop() {
        if (s.top() < 0) {
            mini = mini - s.top(); // Restore the previous minimum
        }
        s.pop();
    }
    
    int top() {
        if (s.top() < 0) {
            return mini; // If the stored value is negative, the top element is the current minimum
        } else {
            return s.top() + mini; // Else return the sum of the stored value and the minimum
        }
    }
    
    int getMin() {
        return mini;
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
