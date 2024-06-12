class Solution {

    private:
void solve(int idx, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int target){

    int n = arr.size();

 

    //base case

    if(target == 0){

        ans.push_back(ds);

        return;

    }

    for(int i = idx; i<n; i++){

        if(i>idx && arr[i] == arr[i-1]) continue;

 

        if(arr[i]>target) break;

 

        ds.push_back(arr[i]);

        solve(i+1, arr, ds, ans, target-arr[i]);

        ds.pop_back();

    }}
public:
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        	 vector<int> ds;

    vector<vector<int>> ans;

 

    sort(v.begin(), v.end());

 

    solve(0, v, ds, ans, target);

    

    return ans;

        
    }
};