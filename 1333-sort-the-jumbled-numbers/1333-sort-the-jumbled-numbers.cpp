#include<bits/stdc++.h>

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
     
      map<int,vector<int>>mp;

    int n=nums.size();
    for(auto it:nums){
        string temp=to_string(it);
        int a=0;
        for(auto x:temp){
            int y=x-'0';
            a=a*10 + mapping[y];
        }
        mp[a].push_back(it);
    }
    vector<int>res;
    for(auto it:mp){
        for(auto i:it.second) res.push_back(i);
    }
    return res;
    }
};