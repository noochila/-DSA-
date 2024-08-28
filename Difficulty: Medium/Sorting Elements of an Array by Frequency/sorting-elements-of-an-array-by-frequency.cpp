//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
     static bool cmp (pair<int,int>& first ,pair<int,int>& second){
         if(first.first == second.first){
             return first.second < second.second;
         }
         return first.first > second.first;
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        //c++ stl
        map<int,int>mp;
        vector<pair<int,int>>vec;//map mapping element ---> frequency
        vector<int>vect;
        for(int i = 0 ; i < arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto iter :mp){
            vec.push_back({iter.second,iter.first});
        }
        sort(vec.begin(),vec.end(),cmp);
        
        for(auto iter : vec){
            for(int i = 0 ; i < iter.first ;i++){
                vect.push_back(iter.second);
            }
        }
        
        return vect;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends