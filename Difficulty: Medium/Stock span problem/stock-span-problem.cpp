//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        
        ///basically count the previous smaller elements
        
        int n=arr.size();
        vector<int>ans(n);
        stack<pair<int,int>>s;
        
        for(int i=0;i<n;i++)
        {
            int count=1;
            while(!s.empty() && arr[s.top().first]<=arr[i])
           { 
               count+=s.top().second;
               s.pop();}
            
            if(s.empty())
            {
                ans[i]=(count);
                s.push({i,count});
            }else
            {
                ans[i]=count;
                s.push({i,count});
            }
            
            
        }
        return ans;
        
        
      
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
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends