class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {


        // for(int i=0;i<arr.size();i++)
        // {
        //     if(arr[i]<=k)
        //     k++;
        //     else
        //    break;
        // }

        // return k;

          int n=arr.size();
        int low=0;
        int high=n-1;

        while(low<=high)
        {
            int mid=(low+high)>>1;

            int missing =arr[mid]-(mid+1);
            if(missing<k)
            low=mid+1;
            else
            high=mid-1;

        }

        return low+k;
    }
};