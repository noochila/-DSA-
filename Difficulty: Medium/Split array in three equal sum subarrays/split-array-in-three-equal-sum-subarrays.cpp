//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        
  int sum = 0;
        for(auto it:arr){
            sum+=it;
        }
        if(sum%3){
            return {-1,-1};
        }
        vector<int>ans;
        int i = 0, temp = 0;
        while(i<arr.size() && ans.size()<2){
            temp+=arr[i];
            if(temp == sum/3){
                ans.push_back(i);
                temp = 0;
            }
            i++;
        }
        if(ans.size() == 2){
            return ans;
        }
        return {-1,-1};
        
        
        
    }
    
    
};

//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends