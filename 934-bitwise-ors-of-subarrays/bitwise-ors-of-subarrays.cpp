class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int>ans;

        unordered_set<int>prev;
        unordered_set<int>cur;

        for (int i=0;i<n;i++){
            int ele=arr[i];
            cur.clear();
            for (auto x:prev) cur.insert(x|ele);
            cur.insert(ele);

            for (auto x:cur) ans.insert(x);
            prev=cur;
        }
        return ans.size();
    }
};