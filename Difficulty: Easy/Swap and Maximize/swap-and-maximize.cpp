//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        
        int n=arr.size(),i=0, j=n-1;
        long long ans=0; vector<int> temp(n);
        sort(arr.begin(), arr.end());
        for(int c=0;c<n;c++){
           if(c%2!=0){
               temp[c]= arr[j];
               j--;
           }
           else{
               temp[c]=arr[i];
               i++;
           }
        }
        for(int i=1;i<n;i++){
            ans+=abs(temp[i]-temp[i-1]);
        }
        ans+=abs(temp[0]-temp[n-1]);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends