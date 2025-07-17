class Solution {
public:
    int dp[1001][1001];
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return helper(nums,k,0,-1);
    }

    int helper(vector<int>&nums,int k,int cur,int modulo){
        if (cur>=nums.size()-1){
            return 0;
        }

        if (dp[cur][modulo+1]!=-1) return dp[cur][modulo+1];
        if (modulo==-1){
            int notPick=helper(nums,k,cur+1,modulo);
            int pick=INT_MIN;

            for (int i=cur+1;i<nums.size();i++){
                pick=max(pick,2+helper(nums,k,i,(nums[cur]+nums[i])%k));
            }

            return dp[cur][modulo+1]=max(pick,notPick);
        }


        for (int i=cur+1;i<nums.size();i++){
            if ((nums[cur]+nums[i])%k==modulo){
                return dp[cur][modulo+1]=1+helper(nums,k,i,modulo);
            }
        }

        return dp[cur][modulo+1]=0;
    }
};