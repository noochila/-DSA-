class Solution {
public:
    long long minimumSteps(string s) {
        
        long long c=0;
        int n=s.size();
        vector<int> prefix(n,0);
        prefix[0]=(s[0]=='1'?1:0);

        for(int i=1;i<s.size();i++)
        {
           if(s[i]=='1')
           prefix[i]+=prefix[i-1]+1;
           else
           {
           
            prefix[i]=prefix[i-1];
            }



        }

        for(int i=n-1;i>0;i--)
        {
            if(s[i]=='0')
            c+=prefix[i-1];
        }
        return c;
        
    }
};