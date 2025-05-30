class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        vector<string>ans;

        unordered_map<string,int>mp;

        int l=0;
        
        for (int r=9;r<n;r++){
            string str=s.substr(l,r-l+1);
            l++;
            mp[str]++;
        }

        for (auto it:mp){
            if (it.second>1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};