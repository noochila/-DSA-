class Solution {
public:
    bool check(vector<int>a,int op,int mid)
    {
        int c=0;
        for(int i=0;i<a.size();i++)
        {
            int num=a[i];
            if (num > mid) {
                c += (num - 1) / mid;
            }
            if (c > op) {
                return false;
            }


        }

        return true;
    }

    int minimumSize(vector<int>& a, int op) {
     int low=1;
     int high=*max_element(a.begin(),a.end());
     int ans;

     while(low<=high)
     {
        int mid=(low+high)/2;
        // cout<<mid<<" "<<check(a,op,mid)<<endl;
        if(check(a,op,mid))
        {
            ans=mid;
            high=mid-1;

        }else
        {
            low=mid+1;
        }
     }

     return ans;    
    }
};