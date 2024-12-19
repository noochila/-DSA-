class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        vector<int>prefixmax;
        vector<int>suffixmin;

        for(int i=0;i<arr.size();i++)
        {
            if(prefixmax.empty() || prefixmax.back()<arr[i])
            prefixmax.push_back(arr[i]);
            else
            prefixmax.push_back(prefixmax.back());
        }
        

        for(int j=arr.size()-1;j>=0;j--)
        {
             if(suffixmin.empty() || suffixmin.back()>arr[j])
             suffixmin.push_back(arr[j]);
             else
             suffixmin.push_back(suffixmin.back());
        }
        reverse(suffixmin.begin(),suffixmin.end());
        int count=0;

        for(int i=0;i<arr.size()-1;i++)
        {

           if(prefixmax[i]<suffixmin[i+1])
           count++;
        }
        return count+1;
    }
};