class Solution {
    public long maxRunTime(int n, int[] batteries) {
        long total = 0L;
        for(int i = 0; i < batteries.length; i++){
            total += (long) batteries[i];
        }

        Arrays.sort(batteries);
        for(int i = batteries.length - 1; i > -1; i--){
            if((long) batteries[i] > total/n){
                total -= batteries[i];
                n--;
            }
            else return total/n;
        }

        return 0;
    }
}