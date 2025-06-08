class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>>dp;
    vector<int>val;
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        val=vals;

        vector<vector<int>>adj(vals.size());

        for (int i=0;i<par.size();i++){
            if (par[i]!=-1){
                adj[par[i]].push_back(i);
            }
        }

        int ans=0;

        for (int i=0;i<vals.size();i++){
            vector<int>nodes;
            getNodes(adj,nodes,i);
            dp.assign(nodes.size(),vector<int>(1<<10,-1));
            ans=(ans+helper(val,nodes,0,0))%mod;
        }
        return ans%mod;
    }

    void getNodes(vector<vector<int>>&adj,vector<int>&nodes,int node){
        nodes.push_back(node);

        for (auto nei:adj[node]){
            getNodes(adj,nodes,nei);
        }

        return;
    }

    int helper(vector<int>&val,vector<int>&nodes,int ind,int state){
        if (ind>=nodes.size()) return 0;

        if (dp[ind][state]!=-1) return dp[ind][state];

        int curVal=val[nodes[ind]];

        int pick=INT_MIN;
        int notPick=helper(val,nodes,ind+1,state);

        if (!isDigitThere(curVal,state)){
            int newState=getState(curVal,state);
            pick=curVal+helper(val,nodes,ind+1,newState);
        }
        return dp[ind][state]=max(pick,notPick);
    }

    bool isDigitThere(int curVal,int state){
        string digit_str=to_string(curVal);
        int tempState=0;
        for (auto x:digit_str){
            int digit=x-'0';
            if (state&(1<<digit)) return true;
            if (tempState&(1<<digit)) return true;
            tempState|=(1<<digit);
        }
        return false;
    }

    int getState(int curVal,int state){
        string digit_str=to_string(curVal);
        
        for (auto x:digit_str){
            int digit=x-'0';

            state|=(1<<digit);
        }
        return state;
    }
};