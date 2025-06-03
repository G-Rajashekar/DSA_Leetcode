class Solution {
public:
    int dp[1001][1001];
    int minSteps(int n) {
        if (n==1) return  0;
        memset(dp,-1,sizeof(dp));
        return 1+helper(1,1,n);
    }

    int helper(int curA,int copyA,int n){
        if (curA==n) return 0;
        if (curA>n) return 1000000;

        if (dp[curA][copyA]!=-1) return dp[curA][copyA];
        int copyAllPaste=2+helper(curA+curA,curA,n);
        int paste=1+helper(curA+copyA,copyA,n);

        return dp[curA][copyA]=min(copyAllPaste,paste);
    }
};