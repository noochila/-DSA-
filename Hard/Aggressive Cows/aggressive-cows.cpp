//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
 
    bool check(vector<int> &stalls,int dis,int k)
    {
        int prev=stalls[0];
        k--;
        
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-prev>=dis)
            {
                prev=stalls[i];
                k--;
            }
            
            
            if(k==0)
            return true;
            
        }
        
        
        return false;
        
        
        
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high= stalls[stalls.size()-1]-stalls[0];
        int ans=0;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(stalls,mid,k))
            {
                ans=mid;
                low=mid+1;
            }else
            {
                high=mid-1;
            }
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends