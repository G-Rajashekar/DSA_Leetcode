class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre=1;
        int suf=1;

        vector<int>ans(nums.size(),0);


        for (int i=0;i<nums.size();i++){
            ans[i]=pre;
            pre=pre*nums[i];
        }
        for (int i=nums.size()-1;i>=0;i--){
            ans[i]*=suf;
            suf=suf*nums[i];
        }

        return ans;
    }
};