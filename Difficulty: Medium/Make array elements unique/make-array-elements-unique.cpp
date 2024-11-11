//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  struct Compare{
      
     bool operator()(pair<int,int>a,pair<int,int>b)
      {
          if(a.second>b.second)
          return true;
          else if(a.second==b.second)
          return a.first<b.first;
          else
          return false;
      }
      
  };
    int minIncrements(vector<int> arr) {
        // Code here
        
        map<int,int>mp;
        for(auto it:arr)
        mp[it]++;
        
        
       priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>pq;
       
       
       for(auto it:mp)
       {
           if(it.second>1)
           pq.push({it.second-1,it.first});
       }
       
       int op=0;
       while(!pq.empty())
       {
           auto temp=pq.top();
           pq.pop();
           int start=temp.second+1;
           while(temp.first>0)
           {
            if(mp.find(start)==mp.end())
             { 
                 op+=(start-temp.second);temp.first--;
                 mp[start]++;
                 
             }
             
             start++;
        
           }
       }
       
       return op;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends