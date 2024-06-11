class Solution {
  public:
  
    double solve(double x,int n)
    {
        if(n==0)
        return 1;
        double val=solve(x,n/2);
        val=val*val;
        if(n%2)
        val*=x;

        return val; 
     }



    double myPow(double x, int n) {

        double ans=solve(x,n);

        if(n<0)
        return 1.0/ans;
        return ans;
        
        
    }
};