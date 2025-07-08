class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(r,vector<int>(c,-1));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if (vis[i][j]==-1 && grid[i][j]=='1'){
                    dfs(grid,i,j,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        for(int k=0;k<4;k++){
            int nrow=i+delRow[k];
            int ncol=j+delCol[k];
            if (nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]=='1' && vis[nrow][ncol]==-1){
                dfs(grid,nrow,ncol,vis);
            }
        }
        return;
    }
};