class CustomStack {
public:
    vector<int> s;
    int i;
    int n;

    CustomStack(int maxSize) {
        s.resize(maxSize, 0);
        i = -1;
        n = maxSize;
    }

    void push(int x) {

        if (i < n-1) {
            s[++i] = x;
        }
    }

    int pop() {

        if (i == -1)
            return -1;

        int x = s[i--];
        return x;
    }

    void increment(int k, int val) {

        k = min(k, i+1);

        for (int i = 0; i < k; i++)
            s[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */