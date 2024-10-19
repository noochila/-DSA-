//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
    
      if(str.back()=='0'){
           return str;
       }
       else if(str.back()>'5'){
           int i=str.size()-2;
           str[i+1]='0';
           while(i>=0 and str[i]=='9'){
               str[i]='0';
               i--;
           }
           if(i<0){
               str="1"+str;
               return str;
           }
           else{
               str[i]++;
           }
           return str;
       }
       else{
           str.back()='0';
           return str;
       }
    
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends