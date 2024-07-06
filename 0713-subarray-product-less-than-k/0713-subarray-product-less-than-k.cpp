class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {


        int n=nums.size();
        int count=0;

        // for(int i=0;i<n;i++)
        // {
        //     int prod=1;
        //     for(int j=i;j<n;j++)
        //     {

        //         if(prod*nums[j]<k)
        //         {count++;
        //          prod=prod*nums[j];
        //          cout<<i<<" "<<prod<<endl;
        //         }
        //         else
        //         break;
        //     }
        // }

        // return count;

        int i=0;
        int j=0;
        long long prod=1;

        while(j<n)
        {
             prod=prod*nums[j]*1ll;

        
            while( i<=j && prod>=k )
            {
                prod=prod/nums[i];
                i++;       
              
                
            }

              count+=(j-i+1);  
              j++;


        }

        return count;

       
  }
};