class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0) return false;
        for (int i=0;i<32;i++){
            long long val=(long long)pow(3,i);
            if (val==n) return true;
        }
        return false;
    }
};