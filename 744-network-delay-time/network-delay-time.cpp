class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for (auto t:times){
            adj[t[0]].push_back({t[1],t[2]});
            //adj[t[1]].push_back({t[0],t[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(n+1,INT_MAX);

        pq.push({0,k});
        dis[k]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            for (auto nei:adj[it.second]){
                if (dis[nei.first]>nei.second+it.first){
                    dis[nei.first]=nei.second+it.first;
                    pq.push({dis[nei.first],nei.first});
                }
            }
        }

        int ans=*max_element(dis.begin()+1,dis.end());

        return ans==INT_MAX?-1:ans;
    }
};