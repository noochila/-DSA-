//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        
        
        int n=arr.size();
        int prev2 = 0;       
        int prev = arr[0];   
    
        for (int i = 1; i < n; i++) {
            int not_take = prev;          
            int take = arr[i] + prev2;    
            int curr = max(take, not_take);

            prev2 = prev; 
            prev = curr;
        }
        return prev;
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends