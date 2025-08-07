class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int ans=0;

        vector<vector<int>>dp1(n,vector<int>(n,-1));
        vector<vector<int>>dp2(n,vector<int>(n,-1));

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i==j){
                    ans+=fruits[i][j];
                }
            }
        }

        ans+=helper1(fruits,dp1,0,n-1,n);
        ans+=helper2(fruits,dp2,n-1,0,n);

        return ans;
    }

    int helper1(vector<vector<int>>&fruits,vector<vector<int>>&dp,int i,int j,int n){
        if (i>=n || j>=n || j<0) return 0;
        if (i>=j) return 0;
        if (i==n-1 && j==n-1) return 0;

        if (dp[i][j]!=-1) return dp[i][j];
        int op1=helper1(fruits,dp,i+1,j-1,n);
        int op2=helper1(fruits,dp,i+1,j,n);
        int op3=helper1(fruits,dp,i+1,j+1,n);

        return dp[i][j]=fruits[i][j]+max({op1,op2,op3});
    }

    int helper2(vector<vector<int>>&fruits,vector<vector<int>>&dp,int i,int j,int n){
        if (i>=n || j>=n || i<0) return 0;
        if (i<=j) return 0;
        if (i==n-1 && j==n-1) return 0;

        if (dp[i][j]!=-1) return dp[i][j];

        int op1=helper2(fruits,dp,i-1,j+1,n);
        int op2=helper2(fruits,dp,i,j+1,n);
        int op3=helper2(fruits,dp,i+1,j+1,n);

        return dp[i][j]=fruits[i][j]+max({op1,op2,op3});
    }
};