//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        
        int n = citations.size();
        int maxi = *max_element(citations.begin(),citations.end());
        vector<int> freq(maxi+1,0);
        for(auto &ele:citations) freq[ele]++;
        for(int i=maxi-1;i>=0;i--) freq[i]+=freq[i+1];
        for(int i=maxi;i>=0;i--) if(freq[i]>=i) return i;
        return -1;
        
  
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
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends