//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   
   double solve(double b,int e)
   {
       if(e==0)
       return 1;
       
      double ans=solve(b,e/2);
      
      ans=ans*ans;
       
       if(e%2)
       ans*=b;
       
       return ans;
       
   }
    double power(double b, int e) {
        // code here
        
       double ans=1;
       if(b==0)return 0;
       
       ans=solve(b,e);
       if(e>0)
       return ans;
       else
       return (double)1/ans;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends