class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int x=0;

        for(auto it:nums)
        x^=it;

        int count=0;

        for(int i=0;i<32;i++)
        {
            int x1=(k&(1<<i));
            int x2=(x&(1<<i));

            if(x1!=x2)
            count++;

        }


        return count;     
        
    }
};