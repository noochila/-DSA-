//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
  
  vector<int> dx{-1, 0, 1, 0};
  vector<int> dy{0, 1, 0, -1};
   
  bool solve(vector<vector<char>>& mat, string& word, int ind, int i, int j) {
      if (ind == word.size()) // Changed >= to ==
          return true;
        
      if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != word[ind]) 
          return false; // Moved boundary check here to avoid out-of-bounds access

      char temp = mat[i][j];
      mat[i][j] = '.'; // Mark as visited

      bool ans = false;
      for (int k = 0; k < 4; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          ans |= solve(mat, word, ind + 1, nx, ny);
          if (ans) break; // Early exit if word is found
      }

      mat[i][j] = temp; // Restore original character
      return ans;
  }
  
  bool isWordExist(vector<vector<char>>& mat, string& word) {
      for (int i = 0; i < mat.size(); i++) {
          for (int j = 0; j < mat[0].size(); j++) {
              if (mat[i][j] == word[0] && solve(mat, word, 0, i, j))
                  return true;
          }
      }
      return false;
  }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends