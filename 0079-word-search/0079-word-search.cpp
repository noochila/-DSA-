class Solution {
public:
    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, 1, 0, -1};

    bool solve(vector<vector<char>>& board, string& word, int i, int j, int ind) {
        int n = board.size();
        int m = board[0].size();

        if (ind >= word.size()) {
            return true; 
        }

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[ind]) {
            return false; 
        }

        
        char temp = board[i][j];
        board[i][j] = '#';

       
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (solve(board, word, nx, ny, ind + 1)) {
                return true;
            }
        }

        
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(board, word, i, j, 0)) {
                    return true; 
                }
            }
        }

        return false; 
    }
};
