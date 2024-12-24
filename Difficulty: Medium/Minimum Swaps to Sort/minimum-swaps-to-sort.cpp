//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {

  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        int n = arr.size();

        // creating a list of pairs where first element of pair is array
        // element and second element is its position.
        vector<pair<int, int>> cur(n);

        // iterating over the array elements.
        for (int i = 0; i < n; i++) {
            // storing the elements and their position as pair in the list.
            cur[i].first = arr[i];
            cur[i].second = i;
        }
        // sorting the list.
        sort(cur.begin(), cur.end());

        // using boolean list to mark visited elements and currently
        // marking all the nodes as false.
        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // if element is already visited or it is already at
            // correct position, we continue the loop.
            if (vis[i] or cur[i].second == i)
                continue;
            int cycle_size = 0;
            int j = i;

            // while element is not visited, we find out the number of nodes in
            // this cycle and keep incrementing cycle size.
            while (!vis[j]) {
                vis[j] = true;
                j = cur[j].second;
                cycle_size++;
            }
            // updating number of swaps required.
            ans += (cycle_size > 1) ? cycle_size - 1 : 0;
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
        Solution obj;
        cout << obj.minSwaps(arr) << endl;
    }
}

// } Driver Code Ends