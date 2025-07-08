class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int fresh_oranges=0;

        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
                else if (grid[i][j]==1){
                    fresh_oranges++;
                }
            }
        }

        int ans=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first.first;
            int c=it.first.second;
            int tm=it.second;

            ans=max(ans,tm);

            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];

                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},tm+1});
                    grid[nrow][ncol]=2;
                    fresh_oranges--;
                }
            }
        }

        if (fresh_oranges==0) return ans;
        return -1;
    }
};