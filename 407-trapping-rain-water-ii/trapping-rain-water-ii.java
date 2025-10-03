class Solution {
    public int trapRainWater(int[][] heightMap) {
        int n=heightMap.length;
        int m=heightMap[0].length;
        PriorityQueue<int[]>pq=new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
        boolean[][] visited=new boolean[n][m];

        for (int i=0;i<n;i++){
            pq.offer(new int[]{heightMap[i][0],i,0});
            visited[i][0]=true;
            pq.offer(new int[]{heightMap[i][m-1],i,m-1});
            visited[i][m-1]=true;
        }

        for (int j=0;j<m;j++){
            pq.offer(new int[]{heightMap[0][j],0,j});
            visited[0][j]=true;
            pq.offer(new int[]{heightMap[n-1][j],n-1,j});
            visited[n-1][j]=true;
        }

        int water=0;

        int[][] dir={{0,-1},{0,1},{-1,0},{1,0}};

        while(!pq.isEmpty()){
            int[]cell=pq.poll();
            int height=cell[0];
            int i=cell[1];
            int j=cell[2];

            for(int[]d:dir){
                int i_=i+d[0];
                int j_=j+d[1];

                if (i_>=0 && i_<n && j_>=0 && j_<m && !visited[i_][j_]){
                    water+=Math.max(0,height-heightMap[i_][j_]);
                    pq.offer(new int[]{Math.max(height,heightMap[i_][j_]),i_,j_});
                    visited[i_][j_]=true;
                }
            }
        }
        return water;
    }
}