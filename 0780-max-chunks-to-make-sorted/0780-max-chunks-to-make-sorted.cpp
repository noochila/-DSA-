class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        

        int curr=0;
        int ans=0;
        int val=0;
        for(int i=0;i<arr.size();i++)
        {
            curr+=arr[i];
            val+=i;
            if(curr==val)
            ans++;
        }
        return ans;
    }
};