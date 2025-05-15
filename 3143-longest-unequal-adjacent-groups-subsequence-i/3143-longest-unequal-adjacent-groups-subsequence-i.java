class Solution {
    public List<String> getLongestSubsequence(String[] words, int[] groups) {

        int n = words.length;
        int[] dp = new int[n];
        int[] path = new int[n];
        Arrays.fill(path, -1);
        Arrays.fill(dp, 1);

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (groups[i] != groups[j] && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    path[i] = j;

                }
            }

        }

        int maxele = 0;
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxele) {
                maxele = dp[i];
                ind = i;
            }

        }

        List<String> ans = new ArrayList<>();

        for (int i = ind; i != -1; i = path[i]) {
            ans.add(words[i]);
        }

        Collections.reverse(ans);
        return ans;

    }
}