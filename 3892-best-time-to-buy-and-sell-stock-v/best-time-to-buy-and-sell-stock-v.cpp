class Solution {
public:
long long dp[1001][501][3];
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1,sizeof(dp));
        return helper(prices,k,0,0);
    }

    long long helper(vector<int>&prices,int k,int ind,int state){

        if (ind>=prices.size()){
            if (state==0) return 0;
            return -1e18;
        }
        if (k==0) return 0;

        if (dp[ind][k][state]!=-1) return dp[ind][k][state];

        long long ans=INT_MIN;
        if (state==0){
            //skip
            long long skip=helper(prices,k,ind+1,0);
            //buy
            long long buy=-1LL*prices[ind]+helper(prices,k,ind+1,1);
            //sell
            long long sell=1LL *prices[ind]+helper(prices,k,ind+1,2);
            ans=max({skip,buy,sell});
        }
        else if (state==1){
            //skip
            long long skip=helper(prices,k,ind+1,1);
            //sell
            long long sell=1LL*prices[ind]+helper(prices,k-1,ind+1,0);
              ans=max({skip,sell});
        }
        else{
            //skip
            long long skip=helper(prices,k,ind+1,2);
            //buy
            long long buy=-1LL*prices[ind]+helper(prices,k-1,ind+1,0);
              ans=max({skip,buy});
        }
        return dp[ind][k][state]=ans;
    }
};