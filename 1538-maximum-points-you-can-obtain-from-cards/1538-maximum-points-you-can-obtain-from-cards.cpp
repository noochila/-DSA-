class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int i = 0;
        int j = 0;
        int n = cardPoints.size();
        k = n - k;

        if(k==0)
        return sum;

        int sum2 = 0;
        int ans = 0;

        while (j < n) {
            sum2 += cardPoints[j];

            if (j - i + 1 < k) {

                j++;
            } else if (j - i + 1 == k) {
                ans = max(ans, sum - sum2);

                j++;

            } else {
                while (j - i + 1 > k) {
                    sum2 -= cardPoints[i];
                    i++;
                    if(j-i+1==k)
                    ans=max(ans,sum-sum2);
                }

                j++;
            }
        }

        return ans;
    }
};