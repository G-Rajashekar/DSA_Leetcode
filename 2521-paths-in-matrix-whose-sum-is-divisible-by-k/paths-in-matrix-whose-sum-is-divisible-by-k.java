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

        return helper(grid,0,0,k,0,n,m);
    }

    public int helper(int[][] grid,int i,int j,int k,int r,int n,int m){

         if (i>=n || j>=m) return 0;

         if (i==n-1 && j==m-1){
            return (r+grid[i][j])%k==0?1:0;
         }
         int newR=(r+grid[i][j])%k;

         if (dp[i][j][newR]!=-1) return dp[i][j][newR];
         long ways=0;

         ways+=helper(grid,i+1,j,k,newR,n,m);
         ways+=helper(grid,i,j+1,k,newR,n,m);

         return dp[i][j][newR]=(int)ways%MOD;

    }
}