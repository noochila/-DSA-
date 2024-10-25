//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        
        int max_size=ceil(double(n)/(double)2);
        
        int min_size=n-max_size;
        
        sort(arr.begin(),arr.end(),greater<int>());
        
        vector<int> maximum(arr.begin(),arr.begin()+max_size);
        vector<int> minimum(arr.rbegin(),arr.rbegin()+min_size);
        
        int i=0;
        int j=0;
        
        for(;j<max_size  ;i=i+2)
        {
            arr[i]=maximum[j++];
        }
        
        i=1;
        j=0;
        
        for(;j<min_size;i=i+2)
        {
            arr[i]=minimum[j++];
        }
        
        return arr;
        
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
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends