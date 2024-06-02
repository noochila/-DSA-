typedef long long int ll;
#define MAX 100005
#define bitscount 31
int prefix_count[bitscount][MAX];
 
// Function to find the prefix sum
void findPrefixCount(vector <int> arr, int n)
{
 
    // Loop for each bit
    for (int i = 0; i < bitscount; i++) {
 
        // Loop to find prefix count
        prefix_count[i][0] = ((arr[0] >> i) & 1);
        for (int j = 1; j < n; j++) {
            prefix_count[i][j] = ((arr[j] >> i) & 1);
            prefix_count[i][j] += prefix_count[i][j - 1];
        }
    }
}
 
// Function to answer query
int AND(int l, int r)
{
 
    // To store the answer
    int ans = 0;
 
    // Loop for each bit
    for (int i = 0; i < bitscount; i++) {
        // To store the number of variables
        // with ith bit set
        int x;
        if (l == 0)
            x = prefix_count[i][r];
        else
            x = prefix_count[i][r]
                - prefix_count[i][l - 1];
 
        // Condition for ith bit
        // of answer to be set
        if (x == r - l + 1)
            ans = (ans | (1 << i));
    }
 
    return ans;
}
 




// ll AND(int x,int y,vector <int>& nums){
    
    
//     ll g = nums[x];
//     for(int i=x;i<=y;i++){
//         g = (g&nums[i]);
//     }
//     return g;
    
    
// }


class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {    int n = nums.size();findPrefixCount(nums, n);
        ll dmin = 1e18;ll k5=k;
        for (int i = 0, j = 0; j < n; j++) {
            ll d = AND(i,j); //[i............j]
            while (d<=k && i<=j){
                ll d8 = abs(k5-AND(i,j)); 
                dmin = min(dmin,d8);
                
                
                i++;
                
                if(i<=j){
                d = AND(i,j);}
                else{ d = 1e18;
                }
            
            }
            
            //count += (j - i + 1);
            
            
            if(i<=j){
                ll d = abs(k5-AND(i,j)); 
                dmin = min(dmin,d);
            }
            
        }
        /*cout<<dmin<<" ";*/int p = dmin;
        return p;
        
    }
};