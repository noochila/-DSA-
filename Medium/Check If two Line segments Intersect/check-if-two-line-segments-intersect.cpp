//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  float line(int p1[], int q1[], int p2[]){
        float m = ((float)q1[1] - p1[1]) / ((float)q1[0] - p1[0]);
        return (float)p2[1] - p1[1] - m * (p2[0] - p1[0]);
    }

    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        float val1 = line(p1, q1, p2);
        float val2 = line(p1, q1, q2);
        
        float val11 = line(p2, q2, p1);
        float val12 = line(p2, q2, q1);
        
        if(val1 * val2 <= 0 && val11 * val12 <= 0){
            return "true";
        }
        
        return "false";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends