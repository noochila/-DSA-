//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
       unordered_map<int,int>mp;
       
       
       
       unordered_set<int> s;
       
       int n=arr.size();
       for(int i=n-1;i>=0;i--)
       {
           if(s.find(arr[i])==s.end())
           {
               s.insert(arr[i]);
               mp[arr[i]]=i;
           }
       }
       
       int ans=0;
       
       for(int i=0;i<arr.size();i++)
       {
           if(s.find(arr[i])!=s.end())
           {
               ans=max(ans,mp[arr[i]]-i);
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
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends