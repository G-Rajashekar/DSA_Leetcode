class Solution {
    public int swimInWater(int[][] grid) {
        int n=grid.length;
        PriorityQueue<int[]>pq=new PriorityQueue<>((int[] a,int[] b)->(a[0]-b[0]));
        
        boolean[][] visited=new boolean[n][n];

        pq.offer(new int[]{grid[0][0],0,0});
        visited[0][0]=true;

        int[] drow={-1,0,+1,0};
        int[] dcol={0,+1,0,-1};
        
        while(!pq.isEmpty()){
            int[] top=pq.poll();
            int ele=top[0],r=top[1],c=top[2];

            if (r==n-1 && c==n-1) return ele;

            for (int d=0;d<4;d++){
                int nrow=drow[d]+r;
                int ncol=dcol[d]+c;

                if (nrow>=0 && ncol>=0 && nrow<n && ncol<n && !visited[nrow][ncol]){
                    visited[nrow][ncol]=true;

                    pq.offer(new int[]{Math.max(ele,grid[nrow][ncol]),nrow,ncol});
                }
            }
        }
        return -1;
    }
}