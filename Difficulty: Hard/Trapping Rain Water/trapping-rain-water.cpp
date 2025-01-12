//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        
        int leftmax=0;
        int rightmax=0;
        int i=0;
        int n=arr.size();
        int j=n-1;
        
        int ans=0;
        
        while(i<j)
        {
            if(arr[i]<arr[j])
            {
                
                if(leftmax<arr[i])
                {
                    leftmax=arr[i];
                }else
                {
                    ans+=(leftmax-arr[i]);
                }
                i++;
                
            }else
            {
                
                if(rightmax<arr[j])
                {
                    rightmax=arr[j];
                }else
                {
                    ans+=(rightmax-arr[j]);
                }
                j--;
                
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends