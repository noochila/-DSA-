//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        
            priority_queue<pair<int,int>> maxh;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        
        maxh.push({arr[0],0});
        minh.push({arr[0],0});
        int cnt=1,temp;
        int start=0,end=0;
        
        int i=0,j=1;
        
        while(j<arr.size())
        {
            maxh.push({arr[j],j});
            minh.push({arr[j],j});
            
            while(maxh.size() && abs(maxh.top().first-arr[j])>x)
            {
                int ind=maxh.top().second;
                if(ind>=i)
                {
                    i=ind+1;
                }
                maxh.pop();
                
            }
            
            while(minh.size() && abs(minh.top().first-arr[j])>x)
            {
                int ind=minh.top().second;
                if(ind>=i)
                {
                    i=ind+1;
                }
                minh.pop();
                
            }
            
            temp=j-i+1;
            
            if(temp>cnt)
            {
                cnt=temp;
                start=i;
                end=j;
            }
            j++;
        }
        
        vector<int> ans;
        for(int i=start;i<=end;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    
        
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends