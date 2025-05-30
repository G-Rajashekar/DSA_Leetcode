class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;

        for (int i=0;i<32;i++){
            int res_c=(1<<i)&c;

            int res_a=(1<<i)&a;

            int res_b=(1<<i)&b;

            if (res_c==0){
                if (res_a!=0 && res_b!=0) ans+=2;
                else if (res_a!=0||res_b!=0) ans+=1;
            }
            else{
                if (res_a==0 && res_b==0) ans+=1;
            }
        }
        return ans;
    }
};