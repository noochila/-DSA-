//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        if(A.size()!=B.size())
        return -1;
        
        map<char,int>mp;
        
        for(int i=0;i<A.size();i++)
      { mp[A[i]]++;
       mp[B[i]]--;}
        
          
        
        
        
        for(auto it:mp)
        {
         if(it.second<0)
         return -1;
        }
        
        
        
         int i=A.size()-1;
         int j=B.size()-1;
         int ans=0;
         while(i>=0 && j>=0)
         {
             if(A[i]==B[j])
             {
                 i--,j--;
             }else 
             {
                 i--;
                 ans++;
             }
         }

         return ans;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends