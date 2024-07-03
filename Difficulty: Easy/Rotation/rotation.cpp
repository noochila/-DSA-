//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	


  int findMin(int arr[],int n)
  {
      int ans=INT_MAX;
      int low=0;
      int high=n-1;
      
      int ind=-1;
      
      while(low<=high)
      {
          if(arr[low]<=arr[high])
          {
              if(arr[low]<ans){
              ans=arr[low];
              ind=low;
             break;}
          }
          
          
          int mid=(low+high)/2;
          if(arr[low]<=arr[mid])
          {
              if(arr[low]<ans)
              {
                  ans=arr[low];
                  ind=low;
               
              }
                 low=mid+1;
          }else
          {
              if(arr[mid]<ans)
              {
                  ans=arr[mid];
                  ind=mid;
                  
              }
              high=mid-1;
          }
      }
      return ind;
  }
	int findKRotation(int arr[], int n) {
	    // code here
	    
	   return findMin(arr,n);
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends