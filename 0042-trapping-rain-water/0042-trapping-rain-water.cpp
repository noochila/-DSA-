class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();
        
        int leftmax=0;
        int rightmax=0;

        int i=0;

        int j=n-1;

        int ans=0;

        while(i<=j)
        {
            if(height[i]<=height[j])
            {
                if(height[i]>=leftmax)
                leftmax=height[i];
                else
                ans+=leftmax-height[i];
                i++;

               
            }else
            {
                  if(height[j]>=rightmax)
                rightmax=height[j];
                else
                ans+=rightmax-height[j];

                j--;

         

            }

           

        }

        return ans;


        
    }
};