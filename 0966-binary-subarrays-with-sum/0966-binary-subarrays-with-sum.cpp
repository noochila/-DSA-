class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mp;
  mp[0]=1;
  int sum=0;
  int ans=0;

  for(int i=0;i<n;i++)
  {
      sum+=arr[i];
      int prefix=sum-k;

          ans+=mp[prefix];
      mp[sum]++;

  }
  return ans;

        
    }
};