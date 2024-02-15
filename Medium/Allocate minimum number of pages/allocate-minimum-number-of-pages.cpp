//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    int check(int A[], int N,int val, int M)
    {
        int books=1;
        
        int sum=0;
        
        
        for(int i=0;i<N;i++)
        {
            if(sum+A[i]>val)
            {
                sum=A[i];
                books++;
                
                if(books>M)
                return false;
            }else
            {
                sum+=A[i];
            }
           
           
        }
        
        return true;
        
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        
        if(N<M)
        return -1;
        
        
        
    
        
        
        int low=*max_element(A,A+N);
        int high=accumulate(A,A+N,0);
        int ans=0;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(check(A,N,mid,M))
            {
                ans=mid;
                high=mid-1;
            }else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends