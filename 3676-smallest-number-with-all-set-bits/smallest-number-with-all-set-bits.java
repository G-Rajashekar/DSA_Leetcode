class Solution {
    public int smallestNumber(int n) {
        while (true) {
            int sum = 0;
            for (int i = 0; i < 32; i++) {
                if ((n & (1 << i)) != 0) {
                    sum += (1 << i);
                } else {
                    break;
                }
            }
            if (sum == n) return n;
            n++;
        }
    }
}
