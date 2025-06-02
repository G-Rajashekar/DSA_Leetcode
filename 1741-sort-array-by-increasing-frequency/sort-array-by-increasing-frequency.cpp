class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;

        for (auto ele:nums){
            mp[ele]++;
        }

        vector<pair<int,int>>arr;
        for (auto it:mp){
            arr.push_back({it.second,it.first});
        }

        sort(arr.begin(),arr.end(),comp);

       vector<int>ans;

      for (int i=0;i<arr.size();i++){
          for (int j=0;j<arr[i].first;j++){
            ans.push_back(arr[i].second);
          }
      }
       return ans;
    }

    static bool comp(pair<int,int>&a,pair<int,int>&b){
        if (a.first!=b.first){
            return a.first<b.first;
        }

        return a.second>b.second;
    }
};