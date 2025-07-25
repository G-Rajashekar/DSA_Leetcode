class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1;
        int i=0;

        while(i<nums.size()){
            if (abs(nums[nums.size()-1]-nums[i])>k) ans++;
            int start=i;
            while(i<nums.size() && abs(nums[i]-nums[start])<=k) i++;
        }
        return ans;
    }
};