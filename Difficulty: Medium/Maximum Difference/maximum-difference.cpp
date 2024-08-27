//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    
    vector<int> leftsmaller(vector<int>&arr)
    {
        stack<int> s;
        vector<int> ans;
        
         for(int i=0;i<arr.size();i++)
         {
             while(!s.empty() && s.top()>=arr[i])
             s.pop();
             
             if(s.empty())
             ans.push_back(0);
             else
             ans.push_back(s.top());
             
             s.push(arr[i]);
         }
         
         
         
         return ans;
    }
    
        vector<int> rightsmaller(vector<int>&arr)
    {
        stack<int> s;
        vector<int> ans;
        
         for(int i=arr.size()-1;i>=0;i--)
         {
             while(!s.empty() && s.top()>=arr[i])
             s.pop();
             
             if(s.empty())
             ans.push_back(0);
             else
             ans.push_back(s.top());
             
             s.push(arr[i]);
         }
         
         reverse(ans.begin(),ans.end());
         
         
         return ans;
    }
    
    
    
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        
        
        int ans=0;
        
        vector<int> a=leftsmaller(arr);
        vector<int> b=rightsmaller(arr);
        
        for(int i=0;i<arr.size();i++)
        {
            ans=max(ans,abs(a[i]-b[i]));
            
        }
        return ans;
        
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends