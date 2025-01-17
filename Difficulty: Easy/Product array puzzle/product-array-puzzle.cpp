//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        
        int prod=1;
        int n=arr.size();
        vector<int>ans1(n);
         vector<int>ans2(n);
        for(int i=0;i<arr.size();i++)
        {
            prod*=arr[i];
            ans1[i]=prod;
            
        }
        prod=1;
        
        for(int i=n-1;i>=0;i--)
        {
            prod*=arr[i];
            ans2[i]=prod;
            
        }
        
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            int temp=1;
            if(i-1>=0)
            temp*=ans1[i-1];
            if(i+1<n)
            temp*=ans2[i+1];
            
            ans[i]=temp;
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends