//{ Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N)
	{
	   // Your code goes here
	   
	   vector<int> prefix(1e5+1,0);
	   
	   for(int i=0;i<N;i++)
	   {
	       int x=Entry[i];
	       int y=Exit[i];
	       
	       prefix[x]+=1;
	       prefix[y+1]-=1;
	   }
	   
	   for(int i=1;i<=1e5;i++)
	   prefix[i]+=prefix[i-1];
	   
	   int ans=0;
	   int loc=-1;
	   for(int i=0;i<=1e5;i++)
	   {
	       if(prefix[i]>ans)
	       {
	           ans=prefix[i];
	           loc=i;
	       }
	   }
	   
	   
	   return {ans,loc};
	   
	}

};

//{ Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends