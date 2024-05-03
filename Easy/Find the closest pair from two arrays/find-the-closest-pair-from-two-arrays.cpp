//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {

    int l = 0, r = m - 1; // Initialize left and right pointers
    int a = 0, b = 0; // Initialize variables to store the indices of the closest pair
    int xmin = INT_MAX; // Initialize minimum difference to maximum possible value

    while (l <n && r >= 0) { // Loop until pointers are within bounds
        const int s = arr[l] + brr[r]; // Calculate the sum of elements at current indices
        const int xcur = abs(x - s); // Calculate the absolute difference from the target

        if (xcur < xmin) { // If the current difference is smaller than the minimum difference
            xmin = xcur; // Update the minimum difference
            a = l; // Update the index of the element in arr
            b = r; // Update the index of the element in brr
        }

        if (s < x) // If sum is less than the target
            ++l; // Move left pointer to the right
        else // If sum is greater than or equal to the target
            --r; // Move right pointer to the left
    }

    return {arr[a], brr[b]}; // Return the closest pair
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends