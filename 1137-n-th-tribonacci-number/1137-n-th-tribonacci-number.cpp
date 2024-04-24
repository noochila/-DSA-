class Solution {
public:
    int tribonacci(int n) {

        if(n==0)
        return 0;


        int a=0;
        int b=1;
        int c=1;

        for(int i=3;i<=n;i++)
        {
            int d=a+b+c;
            
            a=b;
            b=c;
            c=d;
            // cout<<a<<" "<<b<<" "<<c<<endl;



        }
       return c;

        
    }
};