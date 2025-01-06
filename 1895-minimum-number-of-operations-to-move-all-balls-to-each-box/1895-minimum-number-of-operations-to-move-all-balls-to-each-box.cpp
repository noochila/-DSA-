class Solution {
public:
   vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> answer(n, 0);

        int cumValue    = 0;
        int cumValueSum = 0;

        //Find moves for all left balls to index i
        //O(n)
        for(int i = 0; i < n; i++) {
            answer[i] = cumValueSum;
            
            cumValue += boxes[i] == '0' ? 0 : 1;
            
            cumValueSum += cumValue;
        }

        cumValue    = 0;
        cumValueSum = 0;
        //Find moves for all right balls to index i
        //O(n)
        for(int i = n-1; i >= 0; i--) {
            answer[i] += cumValueSum;
            
            cumValue += boxes[i] == '0' ? 0 : 1;
            
            cumValueSum += cumValue;
        }

        //O(n+n) ~ O(n)
        return answer;

    }
};