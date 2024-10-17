class Solution {
public:
    int maximumSwap(int num) {

        string s=to_string(num);

        int n=s.size();
        if(n==1)
        return num;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string temp=s;
                ans=max(ans,stoi(temp));
                swap(temp[i],temp[j]);
                ans=max(ans,stoi(temp));

            }
        }
        return ans;



        
    }
};