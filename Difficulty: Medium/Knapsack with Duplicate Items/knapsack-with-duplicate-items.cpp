//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        
       vector<int> prev(W + 1, 0), curr(W + 1, 0);
        
        // Step 1: Base cases
        for(int w=1; w<=W; w++){
            prev[w] = ((int) w / wt[0]) * val[0];
        }
        
        // Step 2: Represent all the states
        for(int ind=1; ind<N; ind++){
            
            for(int w=1; w<=W; w++){
                
                // Step 3: Copy recursion
                int notTake = prev[w];
        
                int take = -1e9;
                if(wt[ind] <= w) take = val[ind] + curr[w - wt[ind]];
                
                curr[w] = max(take, notTake);
                
            }
            
            prev = curr;
            
        }
        
        return prev[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends