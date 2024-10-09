class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& a, vector<int>& b) {
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int j=0;
        int c=0;

        for(int i=0;i<a.size();i++)
        { 
            while(j<b.size() && b[j]<a[i])
            j++;

            if(j<b.size())
            {c++;
            j++;}
        }

        return c;
    }
};