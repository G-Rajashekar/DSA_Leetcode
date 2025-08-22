class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int c1=INT_MAX;
        int c2=INT_MIN;
        int r1=INT_MAX;
        int r2=INT_MIN;

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1){
                    c1=min(c1,j);
                    c2=max(c2,j);
                    r1=min(r1,i);
                    r2=max(r2,i);
                }
            }
        }
        int l=c2-c1+1;
        int b=r2-r1+1;

        return l*b;
    }
};