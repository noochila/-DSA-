//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

 int findFloor(int v[], int n, int  x) {

        // Your code here
      int low=0;
      int high=n-1;
        
        while(low<=high)
        {
          int mid=low+(high-low)/2;
            
            if(v[mid]<=x)
            low=mid+1;
            else
            high=mid-1;
        }
        if(high!=-1)
        return v[high];
        else
        return -1;
    }
    
    
     int findCeil(int v[], int n, int  x) {

        // Your code here
      int low=0;
      int high=n-1;
        
        while(low<=high)
        {
          int mid=low+(high-low)/2;
            
            if(v[mid]<x)
            low=mid+1;
            else
            high=mid-1;
        }
        if(low!=n)
        return v[low];
        return -1;
    }
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr,arr+n);
    int p=findCeil(arr,n,x);
    int q=findFloor(arr,n,x);
    
    return {q,p};
    
    
    
}