//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        
        set<int>s;
        
        vector<int>ans;
        
        int i=0;
        int j=0;
        int n=arr.size();
        map<int,int>mp;
        
        while(j<n)
        {
            if(j-i+1<k)
            {
                mp[arr[j]]++;
                s.insert(arr[j]);
                j++;
            }else if(j-i+1==k)
            {
                mp[arr[j]]++;
                s.insert(arr[j]);
                ans.push_back(s.size());
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                {
                mp.erase(arr[i]);
                s.erase(arr[i]);
                    
                }
                i++;
                j++;
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends