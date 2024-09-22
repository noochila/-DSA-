class Solution {
public:
    int countSteps(int& n, int current){
        long steps = 0;
        long first = current, last = current;
        while(first <= n){
            steps = steps + min((long)n+1, last + 1) - first;
            first = first*10;
            last = last*10 + 9; 
        }

        return steps;
    }
    int findKthNumber(int n, int k) {
        int current = 1;
        k--;

        while(k > 0){
            int steps = countSteps(n, current);
            if(steps <= k){
                k = k - steps;
                current++;
            }else{
                k--;
                current = current*10;
            }
        }

        return current;
    }
};