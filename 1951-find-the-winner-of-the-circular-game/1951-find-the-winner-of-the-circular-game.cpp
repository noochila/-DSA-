class Solution {
public:
    
    void solve(vector<int>&a ,int &ans,int ind,int k)
    {
        if(a.size()==1)
        {
            ans=a[0];
            return ;
        } 
        int n=a.size();

        ind=(ind+k)%n;
       a.erase((a.begin()+ind));

       solve(a,ans,ind,k);

    }

   
    int findTheWinner(int n, int k) {

         vector<int> a(n);
         for(int i=0;i<n;i++)
         a[i]=i+1;

        int ans;

        solve(a,ans,0,k-1);

        return ans;






        
    }
};