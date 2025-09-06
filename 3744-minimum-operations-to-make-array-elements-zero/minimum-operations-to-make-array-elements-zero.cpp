class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;

        for (auto q:queries){
            int l=q[0];
            int r=q[1];
            ans+=helper(l,r);
        }
        return ans;
    }

    long long helper(int l,int r){
        long long steps=0;

        long long L=1;
        long long s=1;

        while(L<=r){
            long long R=4*L-1;

            long long start=max(L,(long long)l);
            long long end=min(R,(long long)r);

            if (start<=end){
                steps+=(end-start+1)*s;
            }
            s+=1;
            L*=4;
        }
        return (steps+1)/2;
    }
};