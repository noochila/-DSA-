class NumberContainers {
public:
    unordered_map<int, int> mp;
    unordered_map<int, set<int>> st;
    NumberContainers() {}

    void change(int index, int number) {

        if (mp.find(index)==mp.end()) {
            mp[index] = number;
            st[number].insert(index);
        } else {
            int ele = mp[index];
            st[ele].erase(index);
            st[number].insert(index);
            mp[index] = number;
        }
    }

    int find(int number) {

        if (st[number].size() == 0)
            return -1;
        else
            return *(st[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */