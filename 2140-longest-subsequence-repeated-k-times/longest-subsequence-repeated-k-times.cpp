class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.length();
        string str="";
        queue<string>q;
        q.push(str);
        string ans="";

        vector<int>freq(26,0);

        for (auto x:s){
            freq[x-'a']++;
        }

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for (int i=25;i>=0;i--){
                char c=i+'a';
                string temp=it+c;
                if (temp.size()>7 || freq[i]<k) continue;
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