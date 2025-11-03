class Solution {
    public int minCost(String colors, int[] neededTime) {
        int n = neededTime.length;
        int cost = 0;

        char[] chArr = colors.toCharArray();

        for(int i = 1; i < n; i++){
            int max = neededTime[i-1];
            int sum = neededTime[i-1];

            while( i < n && chArr[i-1] == chArr[i]){
                sum += neededTime[i];
                max = Math.max(max, neededTime[i]);
                i++;
            }

            cost += (sum - max);
        }

        return cost;
    }
}