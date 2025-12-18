class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {
        int n=prices.length;
        
        long base=0;
        long[] profit=new long[n];

        for (int i=0;i<n;i++){
            profit[i]=(long)(strategy[i]*prices[i]);
            base+=profit[i];
        }

        long gain=0;
        long original=0;
        long modified=0;
        int l=0;

        for (int r=0;r<n;r++){
            original+=profit[r];
            
            if (r-l+1>k/2) modified+=prices[r];

            if (r-l+1>k){
                original-=profit[l];
                modified-=prices[l+k/2];
                l++;
            }

            if (r-l+1==k){
                gain=Math.max(gain,modified-original);
            }
        }
        return base+gain;
    }
}