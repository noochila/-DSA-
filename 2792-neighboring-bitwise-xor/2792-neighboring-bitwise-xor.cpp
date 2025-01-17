class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int n=derived.size();

        int firstone=1;
        int firstzero=0;

        for(int i=0;i<n;i++)
        {
            firstone=derived[i]^firstone;
            firstzero=derived[i]^firstzero;

        }

        if(firstone==1 || firstzero==0)
        return true;
        else
        return false;
    }
};