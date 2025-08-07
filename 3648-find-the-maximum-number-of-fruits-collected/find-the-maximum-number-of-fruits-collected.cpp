class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        vector<vector<int>>dp1(n,vector<int>(n,-1));
        vector<vector<int>>dp2(n,vector<int>(n,-1));
        int ans=0;
        for (int i=0;i<n;i++){
            ans+=fruits[i][i];
            fruits[i][i]=0;
        }

        ans+=helper1(fruits,n-1,0,dp1,n);
        ans+=helper2(fruits,0,n-1,dp2,n);
        return ans;
    }

    int helper1(vector<vector<int>>& fruits,int i,int j, vector<vector<int>>&dp,int n){
        if (i<0||j<0||i>=n||j>=n) return -1e9;
        if (i==n-1 && j==n-1) return 0;

        if (dp[i][j]!=-1) return dp[i][j];

        int op1=fruits[i][j]+helper1(fruits,i-1,j+1,dp,n);
        int op2=fruits[i][j]+helper1(fruits,i,j+1,dp,n);
        int op3=fruits[i][j]+helper1(fruits,i+1,j+1,dp,n);

        return dp[i][j]=max(max(op1,op2),op3);
    }

    int helper2(vector<vector<int>>& fruits,int i,int j, vector<vector<int>>&dp,int n){
        if (i<0||j<0||i>=n||j>=n) return -1e9;
        if (i==n-1 && j==n-1) return 0;

        if (dp[i][j]!=-1) return dp[i][j];

        int op1=fruits[i][j]+helper2(fruits,i+1,j-1,dp,n);
        int op2=fruits[i][j]+helper2(fruits,i+1,j,dp,n);
        int op3=fruits[i][j]+helper2(fruits,i+1,j+1,dp,n);

        return dp[i][j]=max(max(op1,op2),op3);
    }
};