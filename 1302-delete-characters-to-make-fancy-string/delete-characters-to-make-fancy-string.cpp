class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();
        if (n<3) return s;

        string res="";
        
        for (int i=0;i<=n-1;i++){
            if (i>n-3){
                res.push_back(s[i]);
                continue;
            }
            if (s[i]==s[i+1] && s[i]==s[i+2]) continue;
            else res.push_back(s[i]);
        }
        return res;
    }
};