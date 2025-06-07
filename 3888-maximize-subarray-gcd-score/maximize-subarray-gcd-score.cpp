class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>powOf2(n,0);

        for (int i=0;i<n;i++){
            int num=nums[i];
            while(num%2==0){
                powOf2[i]++;
                num/=2;
            }
        }

        long long ans=0;

        for (int i=0;i<n;i++){
            int g=nums[i];
            int minPowOf2=powOf2[i];
            unordered_map<int,int>mp;
            for (int j=i;j<n;j++){
                g=gcd(g,nums[j]);
                minPowOf2=min(minPowOf2,powOf2[j]);
                mp[powOf2[j]]++;
                if (mp[minPowOf2]<=k){
                    ans=max(ans,1LL*(j-i+1)*g*2);
                }
                else{
                    ans=max(ans,1LL*(j-i+1)*g);
                }
            }
        }
        return ans;
    }
};