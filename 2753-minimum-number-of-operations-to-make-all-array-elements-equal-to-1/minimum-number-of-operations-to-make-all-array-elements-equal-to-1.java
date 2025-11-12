class Solution {
    public int minOperations(int[] nums) {
        int n=nums.length;
        int cnt1=0;

        for (int num:nums){
            if (num==1) cnt1++;
        }

        if (cnt1>0) return n-cnt1;
        int best=Integer.MAX_VALUE;

        for (int i=0;i<n-1;i++){
            int gcd=nums[i];
            for (int j=i+1;j<n;j++){
                gcd=helper(gcd,nums[j]);
                if (gcd==1){
                    best=Math.min(best,j-i);
                    break;
                }
            }
        }
        if (best==Integer.MAX_VALUE) return -1;

        return n-1+best;
    }

    public int helper(int a,int b){
        while(b!=0){
            int temp=a%b;
            a=b;
            b=temp;
        }
        return a;
    }
}