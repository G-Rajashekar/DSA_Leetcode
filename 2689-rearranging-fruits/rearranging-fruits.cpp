class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n1=basket1.size();
        int n2=basket2.size();
        int mini=INT_MAX;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        for (int i=0;i<n1;i++){
            mp1[basket1[i]]++;
            mp2[basket2[i]]++;
            mini=min(basket1[i],mini);
            mini=min(basket2[i],mini);
        }
        vector<int>to_swap;

        for (auto it:mp1){
            int val=it.first;
            int freq=it.second;
            int freq2=mp2[val];

            int diff=abs(freq-freq2);
            if (diff%2) return -1;
            diff/=2;

            for (int i=0;i<diff;i++) to_swap.push_back(val);
            mp2[val]=0;
        }

        for (auto it:mp2){
            int val=it.first;
            int freq=it.second;
            
            if (freq%2) return -1;

            for (int i=0;i<freq/2;i++) to_swap.push_back(val);
        }

        sort(to_swap.begin(),to_swap.end());
        long long ans=0;
        for (int i=0;i<to_swap.size()/2;i++){
            ans+=min((long long)to_swap[i],2*(long long)mini);
        }
        return ans;
        
    }
};