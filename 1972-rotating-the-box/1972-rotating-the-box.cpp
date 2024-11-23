class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int n = box.size();
        int m = box[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j > 0; j--) {
                int k = j;

                while (k < m && box[i][k] == '.' && box[i][k - 1] == '#') {
                    swap(box[i][k], box[i][k - 1]);
                    k++;
                }
            }
        }
        /*

         [[".","#","*","."],
         ["#","#","*","."]]

         [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]



        */

    vector<vector<char>> ans;
    for(int i=0;i<m;i++)
    {
       vector<char>temp;
       for(int j=n-1;j>=0;j--)
       temp.push_back(box[j][i]);

       ans.push_back(temp);
    }
    return ans;

    }
};