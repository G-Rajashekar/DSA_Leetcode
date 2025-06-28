class Solution {
public:
    static bool comp(pair<int,int>&p1,pair<int,int>&p2){
        return p1.first>p2.first;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>Sorted;

        for (int i=0;i<n;i++){
            Sorted.push_back({nums[i],i});
        }

        sort(Sorted.begin(),Sorted.end(),comp);
        
        vector<int>indexes;

        for (int i=0;i<k;i++){
            indexes.push_back(Sorted[i].second);
        }
        sort(indexes.begin(),indexes.end());
        
        for (int i=0;i<k;i++){
            indexes[i]=nums[indexes[i]];
        }
        return indexes;
    }
};