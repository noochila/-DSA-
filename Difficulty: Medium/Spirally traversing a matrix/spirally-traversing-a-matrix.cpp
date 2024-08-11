//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
           vector<int> v;
       int left=0,right=matrix[0].size()-1,top=0,down=matrix.size()-1;
       int flag=0;
       while(left<=right and top<=down){
           if(flag==0){
               for(int i=left;i<=right;i++) v.push_back(matrix[top][i]);
               top++;
           }
           else if(flag==1){
               for(int i=top;i<=down;i++) v.push_back(matrix[i][right]);
               right--;
           }
           else if(flag==2){
               for(int i=right;i>=left;i--) v.push_back(matrix[down][i]);
               down--;
           }
           else{
               for(int i=down;i>=top;i--) v.push_back(matrix[i][left]);
               left++;
           }
           flag=(flag+1)%4;
       }
       return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends