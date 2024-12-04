class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {

        int i=str1.size();
        int j=str2.size();
        i-=1;
        j-=1;

        while(i>=0 && j>=0)
        {

            // cout<<(str1[i]-'a')<<endl;

            // cout<<i<<" "<<j<<endl;

            
            if(str1[i]==str2[j])
            {
                i--,j--;
            }else if((str1[i]-'a'+1)%26==(str2[j]-'a'))
            {
                i--,j--;
            }else
            {
                i--;
            }
        }

        cout<<i<<" "<<j<<endl;

        if(j>=0)
        return false;
        else
        return true;
    }
};