class Solution {
public:
    int scoreOfString(string s) {
     int sum=0;

     for(int i=1;i<s.size();i++)
     {
        sum+=abs(s[i-1]-s[i]);
     }

     return sum;
        
    }
};