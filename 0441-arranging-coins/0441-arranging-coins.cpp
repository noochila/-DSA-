class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 1)
            return 1;


        

        // for (long long i = 1; i <= n; i++) {
        //     if (i * (i + 1) <= 2LL * n)
        //         continue;
        //     else
        //         return static_cast<int>(i - 1);
        // }

        // return 0;


        int low=1;
        int high=n;
        int ans=0;

        while(low<=high)
        {
            long long mid=low+ (high-low)/2;

            if(mid*(mid+1)<=2ll*n)
            {
                ans=mid;
                low=mid+1;
                
            }else
            high=mid-1;
        }
        return ans;
        // return high;
    }
};
