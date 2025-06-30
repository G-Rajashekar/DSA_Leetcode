class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        for (auto num:nums) mp[num]++;

        vector<pair<int,int>>Sorted;

        for (auto it:mp){
            Sorted.push_back({it.first,it.second});
        }
        int ans=0;

        for (int i=0;i<Sorted.size()-1;i++){
              if (Sorted[i+1].first-Sorted[i].first==1){
                ans=max(ans,Sorted[i].second+Sorted[i+1].second);
              }
        }
        return ans;
    }
};