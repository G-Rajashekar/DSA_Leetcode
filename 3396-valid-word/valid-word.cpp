class Solution {
public:
    bool isValid(string word) {
        if (word.length()<3) return false;

        int v=0;
        int c=0;

        for (auto ch:word){
            if (!isalnum(ch)) return false;
            
            if ((ch>=65 && ch<=90 ||  ch>=97 && ch<=122)){
                if (ch>=65 && ch<=90) ch=ch+32;

                if (ch=='a' ||  ch=='e' || ch=='i' || ch=='o' || ch=='u') v++;
                else c++;
            }
        }

        if (v>=1 && c>=1) return true;
        return false;
    }
};