class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0) return false;
        for (int i=0;i<32;i++){
            long long val=1;
            for (int j=0;j<i;j++){
                val*=3;
            }
            if (val==n) return true;
        }
        return false;
    }
};