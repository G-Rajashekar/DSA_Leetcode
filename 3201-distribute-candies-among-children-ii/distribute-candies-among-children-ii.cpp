class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;

        for (int i=0;i<=min(limit,n);i++){
            int rem=n-i;

            if (rem>2*limit+1) continue;
            else{
                int low=max(0,rem-limit);
                int high=min(limit,rem);
                ans+=(high-low+1);
            }
        }
        return ans;
    }
};