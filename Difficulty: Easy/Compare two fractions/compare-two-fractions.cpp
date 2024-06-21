//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

     int a, b, c, d;
    
    // Use a stringstream to parse the input string
    stringstream ss(str);
    
    // Read the first fraction
    char slash, comma;
    ss >> a >> slash >> b >> comma;
    
    // Read the second fraction
    ss >> c >> slash >> d;
    
    // Cross-multiply to compare without using floating point
    int left = a * d;
    int right = b * c;
    
    if (left > right) {
        return to_string(a) + "/" + to_string(b);
    } else if (left < right) {
        return to_string(c) + "/" + to_string(d);
    } else {
        return "equal";
    }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends