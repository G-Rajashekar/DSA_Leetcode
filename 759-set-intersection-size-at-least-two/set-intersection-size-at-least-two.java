class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] == b[1] ? b[0] - a[0] : a[1] - b[1]);
        int a = -1, b=-1;
        int count = 0;
        for(int[] in : intervals) {
            int start = in[0], end = in[1];
            boolean aIn = a >= start && a<= end;
            boolean bIn = b>=start && b<= end;
            if(aIn && bIn) continue;
            if(aIn) {
                count++;
                b=a;
                a=end;
            } else {
                count += 2;
                b=end-1;
                a=end;
            }
        }
        return count;
    }
}