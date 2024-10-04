class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        int n=skill.size();
        sort(skill.begin(),skill.end());
        
        int i=0;
        int j=n-1;

        int req=skill[i]+skill[j];
         long long ans=skill[i]*skill[j];
        i++;
        j--;
       
        while(i<j)
        {
            int sum=skill[i]+skill[j];
            if(sum!=req)
            return -1;
            ans+=skill[i]*skill[j];
            i++,j--;
        }


        return ans;
         


        
    }
};