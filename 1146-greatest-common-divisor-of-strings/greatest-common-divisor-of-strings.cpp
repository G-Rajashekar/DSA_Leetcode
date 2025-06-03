class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        string s;
        if (n<m){
            s=str1;
        }
        else{
            s=str2;
        }

        for (int i=s.length();i>=1;i--){
            if (isPossible(s.substr(0,i),str1,str2)){
                return s.substr(0,i);
            }
        }
        return "";
    }

    bool isPossible(string s,string str1,string str2){
           auto isRepeated = [&](string& t) {
            int len = s.length();
            if (t.length() % len != 0) return false;
            for (int i = 0; i < t.length(); i += len) {
                if (t.substr(i, len) != s) return false;
            }
            return true;
        };

        return isRepeated(str1) && isRepeated(str2);
    }
};