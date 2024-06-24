
class Solution {
public:

    long long maximumTripletValue(vector<int>& nums) {


        long long n=nums.size();

        vector<long long> pref(n,0);
        pref[1]=nums[0]-nums[1];

        long long ans=0;

        vector<long long> maxi(n,0);
        maxi[0]=nums[0];


        for(int i=1;i<n;i++)
        maxi[i]=max(maxi[i-1],nums[i]*1ll);

        for(long long k=2;k<n;k++)
        {
            long long val=pref[k-1];
     
           
               val = max(val,(maxi[k-1] - nums[k]));

           

            pref[k]=val;

            ans=max(ans,( pref[k-1]*nums[k]));

        }   

        return ans;     
    }
};