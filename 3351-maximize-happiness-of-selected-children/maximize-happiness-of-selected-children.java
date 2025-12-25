class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        int n=happiness.length;
        Arrays.sort(happiness);

        long ans=0;
        int dec=0;
        for (int i=n-1;i>=n-k;i--){
            if ((happiness[i]-dec)>0) ans+=happiness[i]-dec;
            dec++;
        }
        return ans;
    }
}