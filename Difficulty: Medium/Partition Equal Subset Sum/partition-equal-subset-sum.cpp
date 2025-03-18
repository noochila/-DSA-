//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
             
        int sum2=accumulate(arr.begin(),arr.end(),0);
        int n=arr.size();
       double half=(double)sum2/(double)2;
       
       if(ceil(half)==floor(half))
       {
        
        
     
        
        int sum=(int)half;

        
        int dp[n+1][sum+1];
    
        for(int j=0;j<=n;j++)
        dp[j][0]=1;
        
        for(int i=1;i<=sum;i++)
        dp[0][i]=0;
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                
                if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][sum];
           
           
           
           
       }
       else
       return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends