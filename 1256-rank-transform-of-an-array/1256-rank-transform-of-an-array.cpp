class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        map<int, int> rank; 

    
        int r = 1;
        for (const int& it : s) {
            rank[it] = r++;
        }

        
        for (int& it : arr) {
            it = rank[it];
        }

        return arr;
    }
};
