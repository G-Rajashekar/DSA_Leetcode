class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; 
        int setBits=0;

        for (int i=0;i<32;i++){
            if (n & (1<<i)) setBits++;
        }

        return setBits==1?true:false;
    }
};