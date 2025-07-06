class FindSumPairs {
public:
    vector<int>nums1;
    vector<int>nums2;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        
        for (auto x:nums2) mp[x]++;
        
    }
    
    void add(int index, int val) {
        int ele=nums2[index];
        mp[ele]--;
        if (mp[ele]==0) mp.erase(ele);
        nums2[index]=ele+val;
        mp[ele+val]++;
    }
    
    int count(int tot) {
        int pairs=0;
        for (auto x:nums1){
            pairs+=(mp[tot-x]);
        }

        return pairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */