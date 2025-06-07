class Solution {
public:
    string clearStars(string s) {
        int n=s.length();
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>>pq;
        unordered_map<int,bool>mp;

        for (int i=0;i<n;i++){
            if (s[i]=='*') {
                mp[-pq.top().second]=true;
                pq.pop();
            }
            else{
                pq.push({s[i],-i});
            }
        }
        string res="";
        for (int i=0;i<n;i++){
            if (mp.count(i) ||  s[i]=='*') continue;
            else res.push_back(s[i]);
        }

        return res;
    }
};