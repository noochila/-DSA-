class Solution {
public:
int mod=7+1e9;
    int numOfSubarrays(vector<int>& arr) {


        int sum=0;
        map<long long,long long>mp;
        int n=arr.size();
        int c=0;
        mp[0]=1;

        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
           

            if(sum%2)
            mp[1]++;
            else
            mp[0]++;

             if(sum%2)
            c=(c+mp[0])%mod;
            else
            c=(c+mp[1])%mod;

        }

        return c;
        
    }
};