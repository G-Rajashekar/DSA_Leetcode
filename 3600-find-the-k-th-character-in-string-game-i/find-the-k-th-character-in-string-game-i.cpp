class Solution {
public:
    char kthCharacter(int k) {
        string s="a";

        while(s.length()<k){
            string temp=s;
            for (auto x:s){
                if (x=='z') temp+='a';
                else temp+=(x+1);
            }
            s=temp;
        }
        return s[k-1];
    }
};