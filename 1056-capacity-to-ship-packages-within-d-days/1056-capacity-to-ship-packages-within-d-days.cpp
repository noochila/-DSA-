class Solution {
public:


   bool check(vector<int>&weights,int days,int val)
   {
         int cnt=0;
         int day=1;
        
        for(auto it:weights)
        {
            if(it+cnt>val)
            {
                cnt=it;
                day++;

            }else
            cnt+=it;
            if(day>days)
            return false;
        }
        return true;    

         

       
   }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(weights,days,mid))
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};