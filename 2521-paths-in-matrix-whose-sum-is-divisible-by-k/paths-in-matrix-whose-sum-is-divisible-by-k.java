class Solution {
    static final int MOD = 1_000_000_007;
    int [][][] dp;
    public int numberOfPaths(int[][] grid, int k) {
        int n=grid.length;
        int m=grid[0].length;
        dp=new int[n][m][k];

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                Arrays.fill(dp[i][j],-1);
            }
        }

        return helper(grid,0,0,k,0);
    }

    public int helper(int[][] grid,int i,int j,int k,int r){
         int n=grid.length;
         int m=grid[0].length;

         if (i>=n || j>=m) return 0;

         if (i==n-1 && j==m-1){
            return (r+grid[i][j])%k==0?1:0;
         }

         if (dp[i][j][(r+grid[i][j])%k]!=-1) return dp[i][j][(r+grid[i][j])%k];
         long ways=0;

         ways+=helper(grid,i+1,j,k,(r+grid[i][j])%k);
         ways+=helper(grid,i,j+1,k,(r+grid[i][j])%k);

         return dp[i][j][(r+grid[i][j])%k]=(int)ways%MOD;

    }
}