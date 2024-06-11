#include<bits/stdc++.h>

class Solution {
    set<vector<int>> s;

    private:
void printarr(vector<int> &v, int n, vector<int> x, int index) {
  if (index >= n) {
    sort(x.begin(),x.end());
    s.insert(x);
    return;
  }
  printarr(v, n, x, index + 1);
  x.push_back(v[index]);
  printarr(v, n, x, index + 1);

}

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
              vector<int> x;
  printarr(nums, nums.size(), x, 0);


//   sort(nums.begin(),nums.end());

  vector<vector<int>> ans(s.begin(),s.end());
  
  return ans;
        
    }
};