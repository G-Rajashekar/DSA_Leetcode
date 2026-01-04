class Solution {
    public int sumFourDivisors(int[] nums) {
        int n=nums.length;
        int ans=0;

        for (int num:nums){
            int cnt=0;
            int sum=0;

            for (int i=1;i<=num;i++){
                if (num%i==0){
                    sum+=i;
                    cnt+=1;
                }
                if (cnt>4) break;
            }
            if (cnt==4) ans+=sum;
        }
        return ans;
    }
}