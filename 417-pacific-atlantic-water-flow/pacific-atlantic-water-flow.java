class Solution {
    public void dfs(int[][] heights,Set<String>st,int prevHei,int r,int c){
        st.add(Key(r,c));

        int[] drow={-1,0,+1,0};
        int[] dcol={0,1,0,-1};

        for (int k=0;k<4;k++){
            int nrow=r+drow[k];
            int ncol=c+dcol[k];

            if (nrow>=0 && ncol>=0 && nrow<heights.length && ncol<heights[0].length && heights[nrow][ncol]>=prevHei && !st.contains(Key(nrow,ncol))){
                dfs(heights,st,heights[nrow][ncol],nrow,ncol);
            }
        }
    }
    public String Key(int r,int c){
        return r+","+c;
    }
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int n=heights.length;
        int m=heights[0].length;

        Set<String>pac=new HashSet<>();
        Set<String>atl=new HashSet<>();

        for (int r=0;r<n;r++){
            if (!pac.contains(Key(r,0))){
                dfs(heights,pac,heights[r][0],r,0);
            }
            if (!atl.contains(Key(r,m-1))){
                dfs(heights,atl,heights[r][m-1],r,m-1);
            }
        }
        

        for (int c=0;c<m;c++){
             if (!pac.contains(Key(0,c))){
                dfs(heights,pac,heights[0][c],0,c);
            }
            if (!atl.contains(Key(n-1,c))){
                dfs(heights,atl,heights[n-1][c],n-1,c);
            }
        }

        List<List<Integer>>ans=new ArrayList<>();

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (pac.contains(Key(i,j)) && atl.contains(Key(i,j))){
                    ans.add(Arrays.asList(i,j));
                }
            }
        }

        return ans;
    }


}