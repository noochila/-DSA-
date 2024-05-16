//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  
    
   long long int maxSum(long long int a[], int n)
    {
        long long int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=a[i];
        }
        
        return sum;
    }
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        int count=0;
        sort(a,a+n);
        // check for negatives
       int i=0;
       while(count<k && i<n)
       {
           if(a[i]<0)
           {
               a[i]=(-a[i]);
               count++;
           }
           i++;
       }
        
        if(count==k)
        {
            long long int sum=maxSum(a,n);
            return sum;
        }
        
        int minIndex=-1;
        int minNum=INT_MAX;
        
        for(int i=0; i<n; i++)
        {
            if(a[i]<minNum)
            {
                minIndex=i;
                minNum=a[i];
            }
        }
        
        while(count<k)
        {
            a[minIndex]=(-a[minIndex]);
            count++;
        }
        
        long long int sum=maxSum(a,n);
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends