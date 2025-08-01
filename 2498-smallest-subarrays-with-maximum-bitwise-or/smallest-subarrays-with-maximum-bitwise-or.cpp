class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>closest(n,vector<int>(32,-1));
        vector<int>ans(n);

        for (int i=n-1;i>=0;i--){
             int mx=i;
            for (int j=0;j<32;j++){
                if (nums[i]&(1<<j)){
                    closest[i][j]=i;
                }
                else{
                    if (i+1<n){
                        closest[i][j]=closest[i+1][j];
                    }
                }
                mx=max(mx,closest[i][j]);
            }
            ans[i]=mx-i+1;
        }
        return ans;
    }
};

