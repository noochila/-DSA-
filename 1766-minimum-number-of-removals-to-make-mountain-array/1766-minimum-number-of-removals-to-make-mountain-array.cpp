class Solution {
public:
    vector<int> LIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    ans[i] = max(ans[i], 1 + ans[j]);
                }
            }
        }

        return ans;
    }

    vector<int> LDS(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = n -1; i>= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] <nums[i]) {
                    ans[i] = max(ans[i], 1 + ans[j]);
                }
            }
        }

        return ans;
    }

    int minimumMountainRemovals(vector<int>& nums) {


        int ans=1e9;

        vector<int>lis=LIS(nums);
        vector<int>lds=LDS(nums);

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            // cout<<lis[i]<<" "<<lds[i]<<endl;
            if(lis[i]>1 && lds[i]>1)
            ans=min(ans,n+1-lis[i]-lds[i]);
        }



       return ans;
    }
};