class Solution {
public:
    bool isValidPartition(string s, int ind, int target, int sum) {
        if (ind == s.size()) 
            return sum == target;
        
        int num = 0;
        for (int i = ind; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');  
            
            if (num + sum > target) break; 
            
            if (isValidPartition(s, i + 1, target, sum + num)) 
                return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int count = 0;
        
        for (int i = 1; i <= n; i++) {
            int num = i * i;
            string s = to_string(num);
            
            if (isValidPartition(s, 0, i, 0)) 
                count += num;
        }
        
        return count;
    }
};
