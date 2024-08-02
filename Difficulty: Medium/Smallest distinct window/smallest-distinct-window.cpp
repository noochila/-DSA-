//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        
        int i=0;
        int j=0;
       
        unordered_map<char,int>mp;
        for(auto it:str)
        mp[it]++;
        
        
        int k=mp.size();
        
        
        int n=str.size();
        
        mp.clear();
        int len=1e9;
        
        while(j<n)
        {
            mp[str[j]]++;
            
            if(mp.size()==k)
            {
                len=min(len,j-i+1);
                
                while(mp.size()==k)
                {
                    mp[str[i]]--;
                    if(mp[str[i]]==0)
                    mp.erase(str[i]);
                    
                    i++;
                    
                    if(mp.size()==k)
                    len=min(len,j-i+1);
                }
                
            }
            j++;
            
        }
        
        return len;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends