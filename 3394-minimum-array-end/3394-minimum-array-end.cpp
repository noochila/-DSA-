class Solution {
public:
    long long minEnd(int n, int x) {

        long long val;
        long long start=x;
        n--;

        while(n--)
        {
            start=(x|(start+1));
            // cout<<start<<endl;
        }

        return start;


        
    }
};