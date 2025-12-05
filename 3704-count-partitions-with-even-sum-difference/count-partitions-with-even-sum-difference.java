class Solution {
    public int countPartitions(int[] nums) {
        int n=nums.length;
        int[] prefix=new int[n];
        int[] sufix=new int[n];

        prefix[0]=nums[0];

        for (int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        sufix[n-1]=0;

        for (int i=n-2;i>=0;i--){
            sufix[i]=sufix[i+1]+nums[i+1];
        }

        int ans=0;

        for (int i=0;i<n-1;i++){
           if (Math.abs(prefix[i]-sufix[i])%2==0) ans++;
        }
        return ans;
    }
}