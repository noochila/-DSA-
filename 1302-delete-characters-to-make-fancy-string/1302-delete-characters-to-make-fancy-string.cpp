class Solution {
public:
    string makeFancyString(string s) {


        string temp="";

        for(int i=0;i<s.size();i++)
        {
            if(temp.size()>=2 && (temp[temp.size()-2] == temp[temp.size()-1] )&& (s[i]==temp[temp.size()-1]))
            {
                continue;
            }else
            temp+=s[i];
        }

        return temp;



        
    }
};