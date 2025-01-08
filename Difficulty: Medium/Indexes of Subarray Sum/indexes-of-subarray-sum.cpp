//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n=arr.size(); vector<int>prefix(n+1,0);
        map<int,int>mp;
        
        int sum=0;
        mp[0]=0;
       
        for(int i=0;i<n;i++)
     {  
         sum+=arr[i];
         
         int req=sum-target;
         
         if(mp.find(req)!=mp.end())
         {
             return {mp[req]+1,i+1};
             
         }
         
         if(mp.find(sum)==mp.end())
         mp[sum]=i+1;
         
     }
     return {-1};
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends