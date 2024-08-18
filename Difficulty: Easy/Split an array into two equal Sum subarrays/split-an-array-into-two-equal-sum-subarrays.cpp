//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        
        int sum=accumulate(arr.begin(),arr.end(),0);
        
        if(sum%2)
        return false;
        
        else
        {
            
            int req=sum/2;
            int n=arr.size();
            int val=0;
            for(int i=0;i<n;i++)
            {
                val+=arr[i];
                
                if(val==req)
                return true;
                
            }
            
            return false;
            
        }
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends