// class Solution {
// public:
//     int OR[33][1000000];

//     int prefix[33][1000000];

//     int or_(int x, int y) {
//         long long ans;
//         long long k = 0;
//         for (int i = 0; i < 32; i++) {

//             ans = prefix[i][y] - prefix[i][x - 1];

//             if (ans >= 1)
//                 k += pow(2, i);
//         }

//         return k;
//     }

//     void solve(vector<int>& nums) {
//         int n = nums.size();

//         for (int i = 31; i >= 0; i--) {
//             for (int j = 0; j < n; j++) {
//                 OR[i][j] = (nums[j] & (1 << i) ? 1 : 0);
//             }
//         }

//         for (int i = 0; i < 32; i++) {
//             prefix[i][0] = OR[i][0];
//         }

//         for (int i = 0; i < 32; i++) {
//             for (int j = 1; j < n; j++) {
//                 prefix[i][j] = prefix[i][j - 1] + OR[i][j];
//             }
//         }

      
//     }

//     int minimumSubarrayLength(vector<int>& nums, int k) {

//         solve(nums);

//         int len=1e9;

//         int i=0;

//         int ans=0;

//         int n =nums.size();

      
//         for(int j=0;j<n;j++)
//         {

//             ans=ans|nums[j];

//             while(ans>=k && i<=j)
//             {
//                 len=min(len,j-i+1);
//                 ans=or_(i+1,j);
//                 i++;
//             }

//             if(i>j)
//             i=j;

//         }

        
//         return len==1e9?-1:len;
//     }
// };

class Solution {
private:
    void update(vector<int>& bits, int x, int change) {
        // insert or remove element from window, time: O(32)
        for (int i = 0; i < 32; i++) {
            if ((x >> i) & 1) {
                bits[i] += change;
            }
        }
    }
    
    int bitsToNum(vector<int>& bits) {
        // convert 32-size bits array to integer, time: O(32)
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i]) {
                result |= 1 << i;
            }
        }
        return result;
    }
    
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), result = n + 1;
        vector<int> bits(32);
        for (int start = 0, end = 0; end < n; end++) {
            update(bits, nums[end], 1); // insert nums[end] into window
            while (start <= end && bitsToNum(bits) >= k) {
                result = min(result, end - start + 1);
                update(bits, nums[start++], -1); // remove nums[start] from window
            }
        }
        return result != n + 1 ? result : -1;
    }
};