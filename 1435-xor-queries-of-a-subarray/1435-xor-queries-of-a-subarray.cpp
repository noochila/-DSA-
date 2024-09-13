class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<long long> xors(n + 1, 0);

        // Create prefix XOR array
        for (int i = 1; i <= n; i++) {
            xors[i] = xors[i - 1] ^ arr[i - 1];
        }

        int q = queries.size();
        vector<int> ans;
        
        // Process each query
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            // Adjust the calculation to handle the case when l is 0
            long long temp = l == 0 ? xors[r + 1] : xors[r + 1] ^ xors[l];
            ans.push_back(temp);
        }
        
        return ans;
    }
};
