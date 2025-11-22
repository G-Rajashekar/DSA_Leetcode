class Solution {
    public int minimumOperations(int[] nums) {
        int ans=0;

        for (int num:nums){
            if (num==0 || num%3==0) continue;
            else ans++;
        }
        return ans;
    }
}