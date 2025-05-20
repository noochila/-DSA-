class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {

        int n=nums.length;

        int diff[]=new int[n+1];
        Arrays.fill(diff,0);

        for(int i=0;i<queries.length;i++)
        {
            int x=queries[i][0];
            int y=queries[i][1];

            diff[x]+=1;
            diff[y+1]-=1;
        }


        for(int i=1;i<n;i++)
        diff[i]+=diff[i-1];

        for(int i=0;i<n;i++)
        {
            if(nums[i]>diff[i])
            return false;
        }

        return true;



        
    }
}