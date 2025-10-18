class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        int n=nums.length;
        Arrays.sort(nums);

        int ans=n;

        nums[0]-=k;

        for (int i=1;i<n;i++){
            if (nums[i]+k==nums[i-1]){
                nums[i]=nums[i-1];
                ans--;
            }
            else{
                if (nums[i]-k>nums[i-1]+1){
                    nums[i]=nums[i]-k;
                }
                else{
                    nums[i]=nums[i-1]+1;
                }
            }
        }
        return ans;
    }
}