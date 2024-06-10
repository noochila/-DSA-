//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int getLengthofLongestSubstring( vector<int>  s, int k) {
  // Write your code here.

  int i = 0;
  int j = 0;
  int len = 0;
  int n = s.size();
  map<int, int> mp;

  while (j < n) {
    mp[s[j]]++;

    if (mp.size() < k) {
      j++;
    } else if (mp.size() == k){
      len = max(len, j - i + 1);
    j++;}

    else {
      while (mp.size() > k) {
        mp[s[i]]--;
        if (mp[s[i]] == 0) {
          mp.erase(s[i]);
        }
        i++;
      }
      j++;
    }
  }

  return len;
}
    int totalFruits(int N, vector<int> &nums) {
        
        // map<int,int>mp;
        // int len=0;
        // int k=2;
        
        // int i=0;
        // int j=0;
        
        // while(j<N)
        // {
        //     mp[nums[j]]++;
            
        //     if(mp.size()==k)
        //     {
        //         len=max(len,j-i+1);
        //         // cout<<j<<" "<<i<<endl;
                
        //     }else if(mp.size()>k)
        //     {
        //         while(mp.size()>k && i<j)
        //         {
        //             mp[nums[i]]--;
        //             if(mp[nums[i]]=0)
        //             mp.erase(nums[i]);

        //             i++;
                    
                   
        //                 //  cout<<j<<" "<<i<<endl;
            
        //         }
                
        //     }
            
        //     j++;
        // }
        
        // return len;
        
        
  return getLengthofLongestSubstring(nums, 2);
        
      
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends