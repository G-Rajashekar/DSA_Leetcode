class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.length();
        string str="";
        queue<string>q;
        q.push(str);
        string ans="";

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for (char c='z';c>='a';c--){
                string temp=it+c;
                if (temp.size()>7) continue;
                if (isExisit(s,temp,k)){
                    if (ans.size()<temp.size() || temp>ans) ans=temp;
                    q.push(temp);
                }
            }
        }
        return ans;
    }

    bool isExisit(string s,string temp,int k){
        string repeatKTimes="";
        while(k--){
            repeatKTimes+=temp;
        }
        int j=0;

        for (int i=0;i<s.length();i++){
            if (s[i]==repeatKTimes[j]){
                j++;
            }
            if (j==repeatKTimes.size()) return true;
        }
        return false;
    }
};