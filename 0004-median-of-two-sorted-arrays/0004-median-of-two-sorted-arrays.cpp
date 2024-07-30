class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        

        int n1=a.size();
        int n2=b.size();
        int left=(n1+n2+1)/2;

        if(n1>n2)
        return findMedianSortedArrays(b,a);

        int low=0;
        int high=n1;

      int n=(n1+n2);
        while(low<=high)
        {
            int mid1=(low+high)/2;
            int mid2=(left-mid1);

            int l1=-1e9;
            int l2=-1e9;
            int r1=1e9;
            int r2=1e9;

            if(mid1<n1)
            r1=a[mid1];

            if(mid2<n2)
            r2=b[mid2];

            if(mid1-1>=0)
            l1=a[mid1-1];

            if(mid2-1>=0)
            l2=b[mid2-1];

            if(l1<=r2 && l2<=r1)
            {
                if(n%2){
                    return max(l1,l2);
                    
                }else
                {
                    return (double)(max(l1,l2)+min(r2,r1))/(double)2;
                }
            }
            else if(l1>r2)
            high=mid1-1;
            else 
            low=mid1+1;

        }

        return 0;


    }
};