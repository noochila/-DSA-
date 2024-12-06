class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        unordered_map<int,int>mp;
        for(auto it:banned)
        mp[it]++;

        int sum=0;
        int c=0;

        for(int i=1;i<=n;i++)
        {

            if(sum+i>maxSum)
            {
                return c;
            }else
            {
                if(mp.find(i)==mp.end())
                {
                    c++;
                    sum+=i;
                }
            }

        }

        return c;
        
    }
};