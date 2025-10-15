class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int n=nums.size();
        int[] preCompute=new int[n];
        preCompute[n-1]=1;

        for (int i=n-2;i>=0;i--){
            if (nums.get(i)<nums.get(i+1)){
                preCompute[i]=preCompute[i+1]+1;
            }
            else{
                preCompute[i]=1;
            }
        }

        int ans=0;

        int low=1,high=n/2;

        while(low<=high){
            int k=(low+high)/2;
            boolean flag=false;
            for (int i=0;i+2*k-1<n;i++){
                if (preCompute[i]>=k && preCompute[i+k]>=k){
                    flag=true;
                    break;

                }
            }
            if (flag){
                ans=k;
                low=k+1;
            }
            else{
                high=k-1;
            }
        }
        return ans;
    }
}