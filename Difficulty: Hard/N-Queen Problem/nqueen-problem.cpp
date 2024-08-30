//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 vector<vector<int>> ans;
  bool check(vector<vector<int>>&board,int row,int col)
  {
      int n=board.size();
      int trow=row,tcol=col;
      
      while(tcol>=0)
      {
          if(board[trow][tcol])
          return false;
          tcol--;
      }
      
      tcol=col;
      
      while(tcol>=0 && trow>=0)
      {
          if(board[trow][tcol])
          {
              return false;
          }
          
          trow--;
          tcol--;
      }
      
      tcol=col;
      trow=row;
      
      while(tcol>=0 && trow<n)
      {
          if(board[trow][tcol])
          return false;
          
          trow++;
          tcol--;
      }
      return true;
  }

  void solve(vector<vector<int>>&board,int n,int col)
   {
        
           if(col==n)
           {
              vector<int>temp;
              for(int i=0;i<n;i++)
              {
                  for(int j=0;j<n;j++)
                  {
                      if(board[i][j])
                      temp.push_back(j+1);
                  }
              }
              ans.push_back(temp);
           }
           
           for(int row=0;row<n;row++)
           {
               if(check(board,row,col))
               {
                   board[row][col]=1;
                   solve(board,n,col+1);
                   board[row][col]=0;
                   
               }
           }
           
           return ;
   }


    vector<vector<int>> nQueen(int n) {
        // code here
        
        vector<int> board(n,0);
        
        vector<vector<int>> finalboard;
        
        for(int i=0;i<n;i++)
        finalboard.push_back(board);
        

        
        
        
         solve(finalboard,n,0);
         sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends