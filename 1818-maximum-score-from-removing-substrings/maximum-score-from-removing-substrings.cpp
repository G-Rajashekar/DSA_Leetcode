class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans=0;

        if (x>y){
            ans+=removeab(s,x);
            ans+=removeba(s,y);
        }
        else{
            ans+=removeba(s,y);
            ans+=removeab(s,x);
        }
        return ans;
    }

    int removeab(string &s,int p){
        string temp="";
        temp+=s[0];
        int ans=0;

        for (int i=1;i<s.size();i++){
            if (temp.size()>0 && temp.back()=='a' && s[i]=='b'){
                ans+=p;
                temp.pop_back();
            }
            else temp.push_back(s[i]);
        }
        s=temp;
        return ans;
    }

    int removeba(string &s,int p){
        int ans=0;
        string temp="";
        if (!s.empty()) temp+=s[0];

        for (int i=1;i<s.size();i++){
            if (temp.size()>0 && temp.back()=='b' && s[i]=='a') {
                ans+=p;
                temp.pop_back();
            }
            else temp.push_back(s[i]);
        }
        s=temp;
        return ans;
    }
};