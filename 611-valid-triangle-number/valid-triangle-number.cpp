class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int triplets=0;

        for (int i=n-1;i>=2;i--){
            int j=0;
            int k=i-1;
            while(j<k){
                if (nums[j]+nums[k]>nums[i]){
                    triplets+=(k-j);
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return triplets;
    }
};