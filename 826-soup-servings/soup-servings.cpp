class Solution {
public:
    vector<vector<double>>ops={{100,0},{75,25},{50,50},{25,75}};
    double soupServings(int n) {
        if (n>=5000) return 1.0;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1.0));
        return solve(n,n,dp);
    }

    double solve(double a,double b, vector<vector<double>>&dp){
        if (a<=0 && b<=0) return 0.5;
        if (a<=0) return 1.0;
        if (b<=0) return 0.0;

        if (dp[a][b]!=-1.0) return dp[a][b];
        double pro=0.0;

        for (auto op:ops){
            pro+=solve(a-op[0],b-op[1],dp);
        }
        return dp[a][b]=0.25*pro;
    }
};