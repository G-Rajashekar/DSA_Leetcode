class Solution {
public:
     int md=1e9+7;
    int numSubseq(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int ans=0;
        int i=0;
        int j=n-1;

        while(i<n && i<=j){
            while(i<=j && nums[i]+nums[j]>k)j--;
            if (i<=j){
                ans=(ans+BinExp(2,j-i))%md;
            }
            i++;
        }
        return ans;
    }

    long long BinExp(long long a,long long b){
        if (b==0) return 1;

        long long half=BinExp(a,b/2);
        long long res=(half*half)%md;
        if (b%2) res=(res*a)%md;

        return res;
    }
};