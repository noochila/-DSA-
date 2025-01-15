//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        
        for(auto &it:arr)
        {
            if(it==0)
            it=-1;
        }
        
        map<int,int>mp;
        mp[0]=-1;
        
        int sum=0;
        int len=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            // cout<<sum<<endl;
            
            int req=sum;
            
            if(mp.find(req)!=mp.end())
            {
                len=max(len,i-mp[req]);
            }
            
            if(mp.find(sum)==mp.end())
            mp[sum]=i;
            
            
        }
        return len;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends