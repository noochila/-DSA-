class Solution {
public:
    int minBitFlips(int start, int goal) {

        int newans=start^goal;
        int count=0;

        while(newans>0)
        {
            newans=(newans&(newans-1));
            count++;
        }
        return count;
        
    }
};