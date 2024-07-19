class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int maxMin = INT_MIN;
        for (int i = 0; i < m; i++) {
            int min = INT_MAX;
            for (int j = 0; j < n; j++)
                min = std::min(min, matrix[i][j]);
            maxMin = std::max(maxMin, min);
        }

        int minMax = INT_MAX;
        for (int j = 0; j < n; j++) {
            int max = INT_MIN;
            for (int i = 0; i < m; i++)
                max = std::max(max, matrix[i][j]);
            minMax = std::min(minMax, max);
        }
        
        if (maxMin != minMax) return vector<int> { };
        return vector<int> { maxMin };
    }
};