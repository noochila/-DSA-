class MinStack {
public:
stack<pair<int,int>> s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push({val,val});
        }else
        {
            if(s.top().second<val)
            {
                s.push({val,s.top().second});
            }else
            {
                s.push({val,val});
            }
        }
        
    }
    
    void pop() {
        
        // int x=s.top().first:
        if(s.empty())
         return ;
        s.pop();

        
    }
    
    int top() {
        
        if(s.empty())
        return -1;
        int x=s.top().first;
        return x;

        
    }
    
    int getMin() {
           if(s.empty())
        return -1;
        int x=s.top().second;
        return x;
        
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