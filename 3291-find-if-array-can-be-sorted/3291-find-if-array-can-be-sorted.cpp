class Solution {
public:
    bool canSortArray(vector<int>& nums) {

        int i = 0;
        int j = 0;
        int n = nums.size();

        while (j < n) {
            if (__builtin_popcount(nums[i]) == __builtin_popcount(nums[j]))
                j++;
            else {
                cout<<i<<" "<<j<<endl;
                sort(nums.begin() + i, nums.begin() + j);
                i = j;
                
            }
        }
        // cout<<i<<" "<<j<<endl;

        if(__builtin_popcount(nums[i]) == __builtin_popcount(nums[j-1]))
        {
            // cout<<"c,ae";
            sort(nums.begin()+i,nums.begin()+j);
        }


        for(auto it:nums)
        cout<<it<<" ";

        cout<<endl;

        return is_sorted(nums.begin(),nums.end());
    }
};