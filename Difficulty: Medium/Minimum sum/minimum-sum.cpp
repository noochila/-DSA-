//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        
        sort(arr.begin(),arr.end());
        
        string num1="",num2="";
        for(int i=0;i<arr.size();i+=2)
        num1+=to_string(arr[i]);
        
        for(int i=1;i<arr.size();i+=2)
        num2+=to_string(arr[i]);
        
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    std::string result;

    // Loop from the least significant to the most significant digit
    while (i >= 0 || j >= 0 || carry != 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        
        int sum = digit1 + digit2 + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Reverse the result to get the correct order
    std::reverse(result.begin(), result.end());

    // Trim leading zeros
    size_t start = result.find_first_not_of('0');
    return start == std::string::npos ? "0" : result.substr(start);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends