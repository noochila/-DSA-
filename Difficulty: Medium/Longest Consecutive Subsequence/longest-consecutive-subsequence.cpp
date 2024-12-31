//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        
        int ans=0;
        
        set<int>s(arr.begin(),arr.end());
        
        
        for(int i=0;i<arr.size();i++)
        {
            int len=1;
            
            if(s.find(arr[i]-1)==s.end())
            {
                int start=arr[i]+1;
                while(s.find(start)!=s.end())
                {
                    len++;
                    start++;
                    
                }
                ans=max(ans,len);
            }
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends