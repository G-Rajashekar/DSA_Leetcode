class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int rows=grid.length;
        int cols=grid[0].length;

        int ans=0;

        for (int i=0;i<=rows-3;i++){
            for (int j=0;j<=cols-3;j++){
                if (helper(grid,i,j)==true) ans++;
            }
        }
        return ans;
    }

    public boolean helper(int[][] grid,int r,int c){
        Set<Integer>st=new HashSet<>();

        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                int num=grid[r+i][c+j];
                if (num<1 || num>9 || st.contains(num)) return false;
                st.add(num);
            }
        }

        for (int i=0;i<3;i++){
            if (grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!=15) return false;
            if (grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i]!=15) return false;
        }

        if (grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=15) return false;
        if (grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=15) return false;
        return true;
    }
}