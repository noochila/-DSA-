// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k) {
//         int maxi=*max_element(nums.begin(),nums.end());
        
//         int n=nums.size();
//         int i=0;
//         int ans=0;
        
//         int j=i;
//         int count=0;
        
//         while(j<n && i<n)
//         {
             
//             if(nums[j]==maxi || count>=k)
//              {
                
//                 if(nums[j]==maxi)
//                {    count++;
//                  if(count>=k)
//                      ans++;}
//                } 
//               if(count>=k && nums[j]!=maxi)
//                 ans++;
               
            
//            j++;
               
            
//             if(j==n)
//             {
//                 count=0;
//                 i++;
//                 j=i;
//             }
                
//          }
//         return ans;
        
        
        
        
        
//     }
// };
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        
        int i = 0, j = 0, count = 0;
        int maxElement = *max_element(nums.begin(), nums.end());

        while (j < n) {
            if (nums[j] == maxElement) {
                count++;
            }

            while (count >= k) {
                ans += n - j;
                if (nums[i] == maxElement) {
                    count--;
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};
