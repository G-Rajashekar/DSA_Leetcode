class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int l=0;
        int sum=0;
        unordered_map<int,int>mp;
        
        for (int r=0;r<n;r++){
            mp[nums[r]]++;
            sum+=nums[r];
            while(mp.size()<r-l+1 && l<=r){
                mp[nums[l]]--;
                sum-=nums[l];
                if (mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};