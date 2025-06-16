class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        int prev_mini=INT_MAX;

        for (int i=0;i<n;i++){
            if (prev_mini!=INT_MAX && nums[i]>prev_mini) ans=max(ans,nums[i]-prev_mini);
            prev_mini=min(prev_mini,nums[i]);
        }
        return ans;
    }
};