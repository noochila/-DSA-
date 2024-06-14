class MyQueue {
    stack<int> s;

public:
    MyQueue() {}

    void push(int x) { s.push(x); }

    int pop() {
        if (!s.empty()) {

            stack<int> q;
            while (!s.empty()) {
                int x = s.top();
                s.pop();
                q.push(x);
            }
            int y = q.top();
            q.pop();

            while (!q.empty()) {
                int x = q.top();
                q.pop();
                s.push(x);
            }

            return y;

        } else
            return -1;
    }

    int peek() {

        if (!s.empty()) {
            stack<int> q;
            while (!s.empty()) {
                int x = s.top();
                s.pop();
                q.push(x);
            }
            int y = q.top();

            while (!q.empty()) {
                int x = q.top();
                q.pop();
                s.push(x);
            }
            return y;
        }
        return -1;
    }

    bool empty() {
        // Implement the isEmpty() function here.
        if (s.empty())
            return true;
        return false;
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