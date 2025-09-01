class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        int n=classes.length;

        PriorityQueue<double[]>pq=new PriorityQueue<>((a,b)->Double.compare(b[0],a[0]));

        for (int i=0;i<n;i++){
            helper(classes,pq,i);
        }

        while(extraStudents-->0){
            double[] top=pq.poll();
            int i=(int) top[1];

            classes[i][0]++;
            classes[i][1]++;
            helper(classes,pq,i);
        }

        double ans=0.0;

        for (int[] cls:classes){
            ans+=(double)cls[0]/cls[1];
        }

        return ans/n;
    }

    private void helper(int[][] classes,PriorityQueue<double[]>pq,int i){

        double cur=(double) classes[i][0]/classes[i][1];
        double next=(double) (classes[i][0]+1)/(classes[i][1]+1);
        double inc=next-cur;
        pq.offer(new double[]{inc,i});
    }
}