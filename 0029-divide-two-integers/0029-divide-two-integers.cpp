class Solution {
public:
    int divide(int dividend, int divisor) {

         if(dividend==divisor)
         return 1;


         bool check=true;

         if(dividend>=0 && divisor<0)
         check=false;

         if(divisor>=0 && dividend<0)
         check=false;


         long long ans=0;
        long long n=abs(dividend);
        long long d=abs(divisor);


         while(n>=d)
         {

             int count=0;

             while(n>=(d<<(count+1)))
             count++;

             ans+=(1<<count);
             n-=(d<<(count));


         }

         if(ans==(1<<31) && check)
         return INT_MAX;
             if(ans==(1<<31) && !check)
         return INT_MIN;
         return check?ans:(-1)*ans;

     

    }
};