class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n=nums2.size();
        map<int,int>ans;
        stack<int> s;


         for(int i=n-1;i>=0;i--)
         {
             
               while(!s.empty() && nums2[i]>=s.top())
               s.pop();

               if(s.empty())
               {
                ans[nums2[i]]=-1;
                
               }else
               {
                ans[nums2[i]]=s.top();
               }

               s.push(nums2[i]);
         }


         vector<int>temp;
         for(auto it:nums1)
         temp.push_back(ans[it]);

     return temp;
     
        
    }
};