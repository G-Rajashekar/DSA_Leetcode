class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>dp(n,vector<int>(m,0));

        for (int c=0;c<m;c++){
            dp[0][c]=matrix[0][c];
        }

        for (int r=0;r<n;r++){
            dp[r][0]=matrix[r][0];
        }

        for (int i=1;i<n;i++){
            for (int j=1;j<m;j++){
                if (matrix[i][j]==0) dp[i][j]=0;
                else{
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
            }
        }

        int ans=0;

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++) ans+=dp[i][j];
        }

        return ans;
    }
};