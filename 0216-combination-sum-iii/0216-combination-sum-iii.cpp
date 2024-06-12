    class Solution {


        vector<vector<int>> ans;

    private: void sequence(int index,vector<int>& a,vector<int>&x,int k,int sum)
    {
    if(x.size()<=k)
    {
        if(sum==0 && x.size()==k) 
        {
            ans.push_back(x);
            return ;

        }else
        {
            for(int i=index;i<9;i++)
            {
                if(sum<0)
                break;
                else
                {
                    x.push_back(a[i]);
                   sequence(i+1,a,x,k,sum-a[i]); 
                   x.pop_back();  
                       
                  }
            }
        }

    }else
    return ;
    }

    public:
        vector<vector<int>> combinationSum3(int k, int sum) {

            vector<int> x;

            vector<int> a;
            
            for(int i=1;i<10;i++)
            a.push_back(i);

            sequence(0,a,x,k,sum);
            return ans;


            
        }
    };