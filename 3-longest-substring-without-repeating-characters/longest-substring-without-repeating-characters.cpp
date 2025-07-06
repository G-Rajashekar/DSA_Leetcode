class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0;
        int ans=0;

        unordered_map<int,int>mp;

        for (int r=0;r<n;r++){
            mp[s[r]]++;

            while((r-l+1)>mp.size()){
                mp[s[l]]--;
                if (mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            int len=r-l+1;
            ans=max(ans,len);
        }
        return ans;
        
    }
};