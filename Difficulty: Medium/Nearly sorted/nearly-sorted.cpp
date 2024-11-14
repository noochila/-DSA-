//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        
        int n=arr.size();
        
        vector<int> ans;
        
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
            
            if(pq.size()>k)
            {
                ans.push_back(pq.top());
                pq.pop();
            
            }
            
            
           
            
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        
      for(int i=0;i<n;i++)
      arr[i]=ans[i];
      
      
      
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends