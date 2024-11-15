//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        
        
        map<int,int>mp;
        
        if(arr.size()<=1)
        return -1;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:arr)
        {
            if(mp.find(it)==mp.end()){
            pq.push(it);
            if(pq.size()>2)
            pq.pop();
                mp[it]++;
            }
        }
        
        if(pq.size()==2)
        return pq.top();
        else
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends