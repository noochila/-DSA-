//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    
  
    
    int circularSubarraySum(vector<int> &arr) {

        // your code here
       
        int ans=-1e9;
        int n=arr.size();
    
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
           
            
           
                sum+=arr[i];
                
                ans=max(ans,sum);
                
                if(sum<0)
                {
                    sum=0;
                 
                }
            
            
        }
        
        int minsum=1e9;
        
        sum=0;
        for(int i=0;i<n;i++)
        {
           
           sum+=arr[i];
           minsum=min(minsum,sum);
           if(sum>0)
           sum=0;
        }
        int total_sum=accumulate(arr.begin(),arr.end(),0);
        
        if(ans<0)
        return ans;
        
        return max(ans,total_sum-minsum);
       
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
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends