//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        
        int n=arr.size();
    
       // your code here
     vector<int> temp;
     temp.push_back(arr[0]);
     
     for(int i=1;i<n;i++)
     {
         if(temp.back()<arr[i])
         temp.push_back(arr[i]);
         else
         {
             int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[ind]=arr[i];
         }
     }
     
     return temp.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends