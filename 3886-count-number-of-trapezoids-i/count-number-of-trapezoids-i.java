class Solution {

    private final int MOD = (int)1e9 + 7;

    public int countTrapezoids(int[][] points) {
        Map<Integer, Integer> yIdxCount = new HashMap<>();

        for(int point[]: points) {
            yIdxCount.put(point[1], yIdxCount.getOrDefault(point[1], 0) + 1);
        }

        long t = 0, q = 0;
        for(Map.Entry<Integer, Integer> entry: yIdxCount.entrySet()) {
            long count = entry.getValue();
            if(count >= 2) {
                long numOfChoice = nC2(count);
                t += numOfChoice;
                q += (numOfChoice * numOfChoice);
            }
        }
        long ans = (((t * t) - q ) / 2) % MOD;
        return (int)ans;
    }

    private long nC2 (long n) {
        return (n * (n - 1)) / 2;
    }
}