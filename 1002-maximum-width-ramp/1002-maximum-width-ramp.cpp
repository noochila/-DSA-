class Solution {
public:
    int maxWidthRamp(vector<int>& arr) {

        int n = arr.size();

        vector<int> temp(n);
        int ans=0;
        int maxi = arr[n - 1];
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] > maxi)
                maxi = arr[i];

            temp[i] = maxi;
            cout<<" "<<temp[i];
        }

        int i=0;
        int j=0;

        while(i<n && j<n)
        {
            if(arr[i]<=temp[j])
            {
                ans=max(ans,j-i);
                j++;
            }else
            {
                i++;
            }
        }
        return ans;

        // 9 9 9 9 9 9 4 4 4 1
    }
};