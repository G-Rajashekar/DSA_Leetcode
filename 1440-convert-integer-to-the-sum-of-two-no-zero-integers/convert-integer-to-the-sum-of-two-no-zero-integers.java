class Solution {
    public int[] getNoZeroIntegers(int n) {

        for (int i=1;i<n;i++){
            int req=n-i;

            if (!String.valueOf(i).contains("0") && !String.valueOf(req).contains("0")) return new int[]{i,req};
        }
        return new int[]{-1,-1};
    }
}