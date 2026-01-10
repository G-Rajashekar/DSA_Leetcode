class Solution {
    int[][] dp;

    public int minimumDeleteSum(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        dp = new int[n + 1][m + 1];

        // initialize dp with -1
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = -1;
            }
        }

        return solve(0, 0, s1, s2);
    }

    private int solve(int i, int j, String s1, String s2) {
        // both strings finished
        if (i == s1.length() && j == s2.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // s1 finished → delete remaining s2 chars
        if (i == s1.length()) {
            int sum = 0;
            for (int k = j; k < s2.length(); k++) {
                sum += s2.charAt(k);
            }
            return dp[i][j] = sum;
        }

        // s2 finished → delete remaining s1 chars
        if (j == s2.length()) {
            int sum = 0;
            for (int k = i; k < s1.length(); k++) {
                sum += s1.charAt(k);
            }
            return dp[i][j] = sum;
        }

        // characters match
        if (s1.charAt(i) == s2.charAt(j)) {
            return dp[i][j] = solve(i + 1, j + 1, s1, s2);
        }

        // characters don't match
        int deleteS1 = s1.charAt(i) + solve(i + 1, j, s1, s2);
        int deleteS2 = s2.charAt(j) + solve(i, j + 1, s1, s2);

        return dp[i][j] = Math.min(deleteS1, deleteS2);
    }
}
