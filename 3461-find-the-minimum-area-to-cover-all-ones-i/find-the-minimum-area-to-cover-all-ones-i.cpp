class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int c1=m;
        int c2=-1;
        int r1=n;
        int r2=-1;

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1){
                    if (j<c1) c1=j;
                    if (j>c2) c2=j;
                    if (i<r1) r1=i;
                    if (i>r2) r2=i;
                }
            }
        }
        int l=c2-c1+1;
        int b=r2-r1+1;

        return l*b;
    }
};