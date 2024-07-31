//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string>& arr) {
    if (arr.empty()) return "";
    
    string temp = "";
    int mini = INT_MAX;

    for (const auto& str : arr) {
        mini = min(mini, (int)str.size());
    }

    for (int i = 0; i < mini; i++) {
        char c = arr[0][i];
        bool flag = false;

        for (int j = 1; j < arr.size(); j++) {
            if (arr[j][i] != c) {
                flag = true;
                break;
            }
        }

        if (flag) {
            break;
        } else {
            temp += c;
        }
    }
  
      return temp.empty() ? "-1" : temp;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends