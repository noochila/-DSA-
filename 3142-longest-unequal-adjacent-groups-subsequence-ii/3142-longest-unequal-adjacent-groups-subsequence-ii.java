import java.util.*;

class Solution {

    public int check(String w1, String w2) {
        int len1 = w1.length();
        int len2 = w2.length();

        if (len1 != len2)  // You want to compare only words of the same length
            return -1;

        int c = 0;
        for (int i = 0; i < len1; i++) {
            if (w1.charAt(i) != w2.charAt(i))
                c++;
        }

        return c;
    }

    public List<String> getWordsInLongestSubsequence(String[] words, int[] groups) {
        int n = words.length;
        int[] dp = new int[n];
        int[] path = new int[n];

        Arrays.fill(path, -1);

        for (int i = 0; i < n; i++) {
            dp[i] = 1; // base case: single word
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && check(words[i], words[j]) == 1 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    path[i] = j;
                }
            }
        }

        int maxi = 0;
        int ind = -1;

        for (int i = 0; i < n; i++) {
            if (dp[i] > maxi) {
                maxi = dp[i];
                ind = i;
            }
        }

        List<String> ans = new ArrayList<>();
        while (ind != -1) {
            ans.add(words[ind]);
            ind = path[ind];
        }

        Collections.reverse(ans);
        return ans;
    }
}
