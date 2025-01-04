//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        
         map<int, int> mp;
    sort(arr.begin(), arr.end());
    int count = 0;
    int n = arr.size();
    
    // Iterate through each element as the first element in the triplet
    for (int i = 0; i < n - 2; i++) {
        // Reset map for each i
        mp.clear();
        
        // Check pairs after i (i+1 to n-1)
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            int finds = target - sum;
            
            // If finds is already in the map, it means we found a triplet
            if (mp.find(finds) != mp.end()) {
                count += mp[finds];
            }
            
            // Add the current element to the map for future triplets
            mp[arr[j]]++;
        }
    }
    
    return count;
    
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends