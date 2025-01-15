class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n2 = __builtin_popcount(num2); 
        int n1 = __builtin_popcount(num1);

        if (n1 == n2) {
            return num1;
        } else if (n2 > n1) {
           
            int ans = num1;
            int extraBits = n2 - n1;

            for (int i = 0; i < 32 && extraBits > 0; i++) {
                if ((ans & (1 << i)) == 0) { 
                    ans |= (1 << i); 
                    extraBits--;
                }
            }
            return ans;
        } else {
           
            int ans = 0;
            int bitsToKeep = n2;

            for (int i = 31; i >= 0; i--) {
                if (num1 & (1 << i)) {
                    if (bitsToKeep > 0) {
                        ans |= (1 << i);
                        bitsToKeep--;
                    }
                }
            }
            return ans;
        }
    }
};
