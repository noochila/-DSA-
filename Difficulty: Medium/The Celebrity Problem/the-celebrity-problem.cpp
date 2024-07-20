//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
       int celebrity(vector<vector<int>>& M, int n) 
    {
        int low = 0;
        int high = n - 1;

        // Step 1: Find the candidate
        while (low < high) 
        {
            if (M[low][high] == 1) 
            {
                // low knows high, so low cannot be a celebrity
                low++;
            } 
            else 
            {
                // low does not know high, so high cannot be a celebrity
                high--;
            }
        }

        int candidate = low;

        // Step 2: Verify the candidate
        for (int i = 0; i < n; i++) 
        {
            if (i != candidate) 
            {
                // candidate should not know anyone else
                if (M[candidate][i] == 1) 
                {
                    return -1;
                }
                // everyone else should know the candidate
                if (M[i][candidate] == 0) 
                {
                    return -1;
                }
            }
        }

        return candidate;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends