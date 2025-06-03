class Solution {
public:
    int minSteps(int n) {
        if (n==1) return  0;
        return 1+helper(1,1,n);
    }

    int helper(int curA,int copyA,int n){
        if (curA==n) return 0;
        if (curA>n) return 1000000;

        int copyAllPaste=2+helper(curA+curA,curA,n);
        int paste=1+helper(curA+copyA,copyA,n);

        return min(copyAllPaste,paste);
    }
};