//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void solve(int ind, vector<int> &arr, int n, int k, vector<vector<int>> &res, vector<int> ds)
    {
        if(k == 0) 
        {
            res.push_back(ds);
            return;
        }
        
        if(ind < n and arr[ind] <= k) 
        {
            for(int i = ind; i < n; i++) 
            {
                if(i > ind and arr[i] == arr[i - 1])
                    continue;
                    
                ds.push_back(arr[i]);
                solve(i + 1, arr, n, k - arr[i], res, ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> CombinationSum2(vector<int> &arr, int n, int k)
    {
        vector<vector<int>> res;
        vector<int> ds;
        
        sort(arr.begin(), arr.end());
        solve(0, arr, n, k, res, ds);
        
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends