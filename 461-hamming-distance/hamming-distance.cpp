class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;

        for (int i=0;i<32;i++){
            int res1=(1<<i)&x;

            int res2=(1<<i)&y;

            if ((res1==0 && res2!=0) || (res1!=0 &&res2==0)) ans++;
        }

        return ans;
    }
};