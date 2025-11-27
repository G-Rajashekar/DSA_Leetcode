class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int n=nums.length;
        
        long[] prefix=new long[n];
        prefix[0]=nums[0];
        for (int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        long ans=Long.MIN_VALUE;

        for (int i=0;i<k;i++){
            long cur=0;

            for (int j=i;j+k-1<n;j+=k){
                int r=j+k-1;
                cur+=prefix[r]-(j==0?0:prefix[j-1]);

                ans=Math.max(ans,cur);

                if (cur<0) cur=0;

            }
        }
        return ans;
    }
}