//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        
        sort(arr.begin(),arr.end());
        
        int i=0;
        int n=arr.size();
        int j=n-1;
        int c=0;
        
        
        while(i<j)
        {
            int sm=arr[i]+arr[j];
            if(sm<target)
            {
                c+=(j-i);
                i++;
            }else
            {
                j--;
            }
        }
        return c;
        
        
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends