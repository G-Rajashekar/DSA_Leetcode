class Solution {
public:
    bool isPowerOfThree(int n) {

        for (int i=0;i<32;i++){
            long long val=(long long)pow(3,i);
            if (val==n) return true;
        }
        return false;
    }
};