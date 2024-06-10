class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {


        int i=0;
        int j=0;
        int n=nums.size();

        int len=0;

          int ele=0;
        while(j<n)
        { 

            if(nums[j]==0)
            ele++;


            if(ele<=k)
            len=max(len,j-i+1);
            else
            {
                while(ele>k && i<j)
                {
                    if(nums[i]==0)
                    ele--;

                    i++;
                }

            }

            j++;
             
        }

        return len;


    }
};