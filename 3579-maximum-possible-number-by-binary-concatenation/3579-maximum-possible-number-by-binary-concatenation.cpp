class Solution {
public:
   
    string binary(int n) {
        string temp = "";
        if (n == 0) {
            return "0";
        }

        while (n > 0) {
            temp += (n % 2 == 1) ? '1' : '0';
            n = n / 2;
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }

 
    int val(const string& temp) {
        int ans = 0;
        for (char c : temp) {
            ans = (ans << 1) + (c - '0');
        }
        return ans;
    }

    int maxGoodNumber(vector<int>& nums) {
       
        string s1 = binary(nums[0]);
        string s2 = binary(nums[1]);
        string s3 = binary(nums[2]);
  
        int val1 = val(s1 + s2 + s3);
        int val2 = val(s1 + s3 + s2);
        int val3 = val(s2 + s1 + s3);
        int val4 = val(s2 + s3 + s1);
        int val5 = val(s3 + s1 + s2);
        int val6 = val(s3 + s2 + s1);

        
        return max({val1, val2, val3, val4, val5, val6});
    }
};
