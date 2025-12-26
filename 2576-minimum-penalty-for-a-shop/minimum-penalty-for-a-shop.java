class Solution {
    public int bestClosingTime(String customers) {
        int n=customers.length();
        int[] prefix=new int[n+1];
        int no_cus=0;

        for (int i=0;i<n;i++){
            prefix[i]=no_cus;
            if (customers.charAt(i)=='N') no_cus++;
        }
        prefix[n]=no_cus;
        int cus=0;
        int minPen=prefix[n];
        int ans=n;
        for (int i=n-1;i>=0;i--){
            if (customers.charAt(i)=='Y') cus++;

            if (cus+prefix[i]<=minPen){
                minPen=cus+prefix[i];
                ans=i;
            }
        }
        return ans;
    }
}