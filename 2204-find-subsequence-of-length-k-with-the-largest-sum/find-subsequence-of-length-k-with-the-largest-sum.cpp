class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

         for (int i=0;i<nums.size();i++){
            int ele=nums[i];
            pq.push({ele,i});
            if (pq.size()>k) pq.pop();
         }

        set<int>st;

         while(!pq.empty()){
            st.insert(pq.top().second);
            pq.pop();
         }

         vector<int>ans;

         for (int i=0;i<nums.size();i++){
            if (st.count(i)) ans.push_back(nums[i]);
         }
         return ans;
    }
};