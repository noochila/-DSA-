//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        
        int c1=0;
        int c2=0;
        
        int num1=-1;
        int num2=-1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(c1==0 && nums[i]!=num2 )
            {
                c1=1;
                num1=nums[i];
                
            }else if(c2==0 && nums[i]!=num1 )
            {
                c2=1;
                num2=nums[i];
            }else if(nums[i]==num1)
            {
                c1++;
            }else if(nums[i]==num2)
            {
                c2++;
            }else
            {
                c1--;
                c2--;
        
            }
        }
        
        vector<int> ans;
        int n=nums.size();
          c1 = c2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == num1) c1++;
            else if (nums[i] == num2) c2++;
        }

        // Check if they appear more than n / 3 times
        int mini = n / 3 + 1;
        if (c1 >= mini) ans.push_back(num1);
        if (c2 >= mini) ans.push_back(num2);

        
        
        
        if(ans.size()==0)
        return {-1};
        
        return ans;
        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends