class Solution {
public:
    bool isPalindrome(string s) {
        string str="";


        for (auto x:s){
            if (isalnum(x)){
                if (x>=65 && x<=90) str+=(x+32);
                else str+=x;
            }
        }

         int i=0;
        int j=str.length()-1;
        while(i<=j) {
            if (str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};