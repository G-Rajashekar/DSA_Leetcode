class Solution {
    int [][][] dp;
    public int findMaxForm(String[] strs, int m, int n) {
        int l=strs.length;
        int[][] count=new int[l][2];

        for (int i=0;i<l;i++){
            int ones=0;
            int zeros=0;
            for (char ch:strs[i].toCharArray()){
                if (ch=='1') {
                    ones++;
                }
                else{
                    zeros++;
                }
            }
            count[i][0]=zeros;
            count[i][1]=ones;
        }

        dp=new int[m+1][n+1][l];
        
        for (int i=0;i<=m;i++){
            for (int j=0;j<=n;j++){
                Arrays.fill(dp[i][j],-1);
            }
        }

        return helper(count,m,n,0);
    }

    int helper(int[][] count,int m,int n,int ind){
        if (ind>=count.length || (m==0 && n==0)) return 0;

        if (dp[m][n][ind]!=-1) return dp[m][n][ind];

        int include=0;

        if (count[ind][0]<=m && count[ind][1]<=n) include=1+helper(count,m-count[ind][0],n-count[ind][1],ind+1);
        int exclude=helper(count,m,n,ind+1);

        return dp[m][n][ind]=Math.max(include,exclude);
    }
}