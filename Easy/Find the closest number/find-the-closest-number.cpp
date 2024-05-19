//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        
         int ind=-1;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=k)
            {
                 ind=i;
                 break;
                
            }
        }
        
      if(ind==-1)
      return arr[n-1];
        
        
      
        
        if(arr[ind]==k)
        return arr[ind];
        
        else
        {
            if(ind !=0)
            {
                int x=arr[ind-1];
                int y=arr[ind];
                
                if(abs(x-k)<abs(y-k))
                return x;
                else if(abs(x-k)>=abs(y-k))
                return y;
            }else
            {
                return arr[ind];
            }
        }
        
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
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends