class Solution {
public:
    bool isPowerOfFour(int n) {
        for (int i=0;i<32;i++){
            long long val=(long long)pow(4,i);
            if (val==n) return true;
        }
        return false;
    }
};