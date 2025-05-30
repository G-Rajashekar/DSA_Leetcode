class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();

        vector<int>dis1(n,INT_MAX);
        vector<int>dis2(n,INT_MAX);

        vector<bool>vis1(n,false);
        vector<bool>vis2(n,false);

        dis1[node1]=0;
        dis2[node2]=0;

        dfs(edges,dis1,vis1,node1);
        dfs(edges,dis2,vis2,node2);
        int ans=-1;
        int maxi=INT_MAX;
        for (int i=0;i<n;i++){
               if (dis1[i]!=INT_MAX && dis2[i]!=INT_MAX){
                   if (maxi>max(dis1[i],dis2[i])){
                    ans=i;
                    maxi=max(dis1[i],dis2[i]);
                   }
               }
        }

        return ans;
    }

    void dfs(vector<int>&edges,vector<int>&dis,vector<bool>&vis,int node){
        vis[node]=true;

        int nei=edges[node];

        if (nei!=-1 && !vis[nei]){
            dis[nei]=1+dis[node];
            dfs(edges,dis,vis,nei);
        }
    }
};