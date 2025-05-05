//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int result) {
        // code here
         int l=0;
        int r=arr.size()-1;
        while (l<=r){
            int m =l +(r-l)/2;
            if(arr[m]==result)
              return m;
            if(m>l && arr[m-1] ==result)
              return m - 1;
            if(m <r &&arr[m+1]==result)
               return m+1;
            if(arr[m]>result) 
               r =m-2; 
            else
               l =m+2; 
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends