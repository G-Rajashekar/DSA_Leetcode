class Solution {
public:
       string key(int r, int c) {
        return to_string(r) + "," + to_string(c);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        unordered_set<string>pac;
        unordered_set<string>atl;

        int n=heights.size();
        int m=heights[0].size();

        for (int c=0;c<m;c++){
            if (!pac.count(key(0,c))) dfs(heights,0,c,heights[0][c],pac);
            if (!atl.count(key(n-1,c))) dfs(heights,n-1,c,heights[n-1][c],atl);
        }

          for (int r=0;r<n;r++){
            if (!pac.count(key(r,0))) dfs(heights,r,0,heights[r][0],pac);
            if (!atl.count(key(r,m-1))) dfs(heights,r,m-1,heights[r][m-1],atl);
        }

        vector<vector<int>>ans;

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (pac.count(key(i,j)) && atl.count(key(i,j))) ans.push_back({i,j});
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>&heights,int r,int c,int prevHei,unordered_set<string>&st){
        st.insert(key(r,c));

        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        
        for (int k=0;k<4;k++){
            int nrow=drow[k]+r;
            int ncol=dcol[k]+c;

            if (nrow>=0 && ncol>=0 && nrow<heights.size() && ncol<heights[0].size() && heights[nrow][ncol]>=prevHei && !st.count(key(nrow,ncol))){
                dfs(heights,nrow,ncol,heights[nrow][ncol],st);
            }
        }
    }
};