class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) 
    {
         vector<long long>gcdCount(50001,0);

         for(auto child:nums)
         {
            for(int i=1;(i*i)<=child;i++)
            {
                if((child%i)==0)
                {
                    int x=i;
                    int y=child/i;
                    if(x==y)
                    {
                        gcdCount[x]++;
                    }
                    else{
                        gcdCount[x]++;
                        gcdCount[y]++;
                    }
                }
            }
         }

        

         for(int i=1;i<=50000;i++)
         {   
             long long value=gcdCount[i];
             gcdCount[i]=(value*1ll*(value-1))/2ll;
         }

         

         for(int i=50000;i>=0;i--)
         {
             if(gcdCount[i]>0)
             {
                    for(int j=1;(j*j)<=i;j++)
                    {
                        if((i%j)==0)
                        {
                            int x=j;
                            int y=i/j;
                            if(x==y && y!=i)
                            {
                                gcdCount[x]-=gcdCount[i];
                            }
                            else{
                                if(x!=i)
                                gcdCount[x]-=gcdCount[i];
                                if(y!=i)
                                gcdCount[y]-=gcdCount[i];
                            }
                        }
                    }
             }
         }

         for(int i=1;i<=50000;i++)
         {
            gcdCount[i]+= gcdCount[i-1];
         }

         vector<int>ans;

         for(int i=0;i<queries.size();i++)
         {
            long long ind=queries[i]+1;
            int myInd=lower_bound(gcdCount.begin(),gcdCount.end(),ind)-gcdCount.begin();
            ans.push_back(myInd);
         }

         return ans;

        
    }
};