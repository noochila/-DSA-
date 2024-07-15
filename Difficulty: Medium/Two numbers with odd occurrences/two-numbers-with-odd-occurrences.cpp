//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int n)  
    {
        // code here
        long long int x=0;
        for(long long int i=0;i<n;i++)
        x^=Arr[i];
        
        long long int x1=0;
        long long int x2=0;
        long long firstset=((x)&(x-1)^x);
        
        for(long long int i=0;i<n;i++)
        {
            
            if(Arr[i]&firstset)
            {
                x1^=Arr[i];
            }else
            x2^=Arr[i];
            
            
        }
        
        
        if(x1>x2)
        return {x1,x2};
        else
        return {x2,x1};
        
        
        
 
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends