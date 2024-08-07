//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& a, vector<int>& b) {
        // code here
            
       int n1 = a.size();
    int n2 = b.size();

    // Ensure the first array is the smaller one
    if (n1 > n2) {
        return kthElement(k,b, a);
    }

    int low = max(0, k - n2);
    int high = min(n1, k);

    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = k - mid1;

        int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
        int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return -1;  // If no valid k-th element found, return -1 or handle as appropriate
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends