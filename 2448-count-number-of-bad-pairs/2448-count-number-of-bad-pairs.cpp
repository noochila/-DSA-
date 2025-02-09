class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        long long c = 0;

        int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (nums[j] - nums[i] != j - i)
        //             c++;
        //     }
        // }
        // return c;
        map<int, int> mp;
        int total=0;
        for (int i = 0; i < n; i++) {
            int req = (nums[i] - i);
            
          
            int temp=total-mp[req];
            c+=temp;

            // for (auto it : mp) {
            // if (it.first != req)
            //         c += (it.second);
            // }

            mp[req]++;
            total++;
         
        }
        return c;
    }
};