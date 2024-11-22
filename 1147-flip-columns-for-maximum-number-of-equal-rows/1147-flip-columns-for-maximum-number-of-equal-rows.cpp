class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // int n=matrix.size();
        // int m=matrix[0].size();
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     vector<int> inverted(m);
        //     for(int j=0;j<m;j++)
        //     inverted[j]=(1-matrix[i][j]);
        //     int c=0;

        //     for(auto row : matrix)
        //     {
        //         if(row==matrix[i] || row==inverted)
        //         c++;

        //     }
        //     ans=max(ans,c);
        // }

        // return ans;

        unordered_map<string, int> patternFrequency;

        for (auto& currentRow : matrix) {
            string patternBuilder = "";

            // Convert row to pattern relative to its first element
            for (int col = 0; col < currentRow.size(); col++) {
                // 'T' if current element matches first element, 'F' otherwise
                if (currentRow[0] == currentRow[col]) {
                    patternBuilder += "T";
                } else {
                    patternBuilder += "F";
                }
            }

            // Convert pattern to string and update its frequency in map
            patternFrequency[patternBuilder]++;
        }

        // Find the pattern with maximum frequency
        int maxFrequency = 0;
        for (auto& entry : patternFrequency) {
            maxFrequency = max(entry.second, maxFrequency);
        }

        return maxFrequency;
    }
};