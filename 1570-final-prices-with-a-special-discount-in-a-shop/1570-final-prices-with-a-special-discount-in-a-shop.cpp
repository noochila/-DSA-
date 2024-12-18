class Solution {
public:


  vector<int> nextsmaller(vector<int> a)
  {
       vector<int> ans(a.size(),-1);

       stack<int>s;
       for(int i=a.size()-1;i>=0;i--)
       {
           while(!s.empty() && s.top()>a[i])
           s.pop();

           if(!s.empty())
           ans[i]=s.top();

           s.push(a[i]);
       }
       return ans;
  }
    vector<int> finalPrices(vector<int>& prices) {


        vector<int>ans=nextsmaller(prices);

        for(int i=0;i<prices.size();i++)
        {
            if(ans[i]==-1)
            ans[i]=prices[i];
            else
            ans[i]=(prices[i]-ans[i]);
        }
        return ans;
        
    }
};