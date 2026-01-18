class Solution {
    public int largestMagicSquare(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;

        int[][] rowSum=new int[n][m];
        int [][] colSum=new int[n][m];

        for (int i=0;i<n;i++){
            rowSum[i][0]=grid[i][0];
            for (int j=1;j<m;j++){
                rowSum[i][j]=rowSum[i][j-1]+grid[i][j];
            }
        }

        for (int j=0;j<m;j++){
            colSum[0][j]=grid[0][j];

            for (int i=1;i<n;i++){
                colSum[i][j]=colSum[i-1][j]+grid[i][j];
            }
        }

        for (int side=Math.min(n,m);side>=2;side--){
            for (int r=0;r+side-1<=n-1;r++){
                for (int c=0;c+side-1<=m-1;c++){
                    int targetSum=rowSum[r][c+side-1]-(c>0?rowSum[r][c-1]:0);
                    boolean flag=true;
                    for (int i=r;i<=r+side-1;i++){
                        int sum=rowSum[i][c+side-1]-(c>0?rowSum[i][c-1]:0);
                        
                        if (sum!=targetSum){
                            flag=false;
                            break;
                        }
                    }
                    if (!flag) continue;

                    for (int j=c;j<=c+side-1;j++){
                        int sum=colSum[r+side-1][j]-(r>0?colSum[r-1][j]:0);
                         if (sum!=targetSum){
                            flag=false;
                            break;
                        }
                    }

                     if (!flag) continue;

                     int diag=0;
                     int antiDiag=0;

                     for (int k=0;k<side;k++){
                        diag+=grid[r+k][c+k];
                        antiDiag+=grid[r+k][c+side-1-k];
                     }

                     if (diag==targetSum && antiDiag==targetSum) return side;
                }
            }
        }
        return 1;
    }
}