class Solution {


public:

bool solve(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp) {
  if (tar == 0)
    return true;

  if (ind == 0) {
    return tar == arr[ind];
  }

  if (dp[ind][tar] != -1)
    return dp[ind][tar];
  bool val1 = false;

  if (tar - arr[ind] >= 0)
    val1 = solve(ind - 1, tar - arr[ind], arr, dp);
  bool val2 = solve(ind - 1, tar, arr, dp);
  bool val = val1 | val2;

  return dp[ind][tar] = val;
}
    bool canPartition(vector<int>& arr) {

        int sum=0;

	for(auto it:arr)
	sum+=it;

	if(sum%2)
	return false;


    vector<vector<int>> dp(arr.size(),vector<int>(sum/2+1,-1));
	
    return solve(arr.size()-1,sum/2,arr,dp);

        
    }
};
