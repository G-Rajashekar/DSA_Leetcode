class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (k==1) return 'a';

        long long len=1;
        long long newK=-1;
        int op;
        for (int i=0;i<operations.size();i++){
            len*=2;

            if (len>=k){
                op=operations[i];
                newK=k-len/2;
                break;
            }
        }

        char ch=kthCharacter(newK,operations);

        if (op==0) return ch;

        return ch=='z'?'a':ch+1;
    }
};