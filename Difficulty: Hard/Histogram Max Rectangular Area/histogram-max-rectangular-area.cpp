//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  
    int getMaxArea(vector<int> &arr) {
        // Your code here
int n = arr.size();

vector<int> nsl = [&]() {
    stack<int> s;
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }

        ans[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return ans;
}();

vector<int> ngl = [&]() {
    stack<int> s;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }

        ans[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    return ans;
}();

int ans = 0;
for (int i = 0; i < n; i++) {
    // cout<<ngl[i]<<" "<<nsl[i]<<" "<<i<<endl;
    ans = max(ans, arr[i] * (ngl[i] - nsl[i]-1));
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends