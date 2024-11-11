#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Generate all primes up to `n` using the Sieve of Eratosthenes
    vector<int> getPrimes(int n) {
        vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false;

        for (int i = 2; i * i <= n; ++i) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }

        vector<int> ans;
        for (int i = 2; i <= n; ++i) {
            if (primes[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes = getPrimes(1000);  // Generate primes up to 1000
        int n = nums.size();

        for(int i=n-2;i>=0;i--)
        {

            if(nums[i+1]>nums[i])
            continue;
            else
            {
                int prev=0;
                if(i-1>=0)
                prev=nums[i-1];
                int curr=nums[i];

                int next=nums[i+1];

                for(int j=0;j<primes.size();j++)
                {
                    if((curr-primes[j])<next && (curr-primes[j])>0)
                    {
                        nums[i]=(curr-primes[j]);
                        break;
                    }


                }

                if(nums[i]>=nums[i+1])
                return false;

            }
        }

        // for(auto it:nums)
        // cout<<it<<" ";

        

        return true;



        
    }
};
