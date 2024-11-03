#include<bits/stdc++.h>
class Solution {
public:
    bool rotateString(string s, string goal) {

        for(int i=0;i<s.size();i++)

        {
            if(goal.compare(s)==0)
            return true;
            else
            rotate(s.begin(),s.begin()+1,s.end());
        }

        return false;
        
    }
};