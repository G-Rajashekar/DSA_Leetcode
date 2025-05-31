class Solution {
public: 
   int n;
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(n*n+1,INT_MAX);

        pq.push({0,1});
        dis[1]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if (it.second==n*n) return it.first;

            for (int i=it.second+1;i<=min(it.second+6,(n*n));i++){
                auto [r,c]=helper(i);
                int next=board[r][c]==-1?i:board[r][c];
                if (dis[next]>it.first+1){
                    dis[next]=it.first+1;
                    pq.push({it.first+1,next});
                }
            }
        }

        return -1;
    }

    pair<int,int> helper(int x){
         int r = (x - 1) / n;
        int c = (x - 1) % n;
        if (r & 1) c = (n - 1) - c;
        r = (n - 1) - r;
        return {r, c};
    }
};