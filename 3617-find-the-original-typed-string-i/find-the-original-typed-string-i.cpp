class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<char,int>mp;
        int freq=1;
        char c=word[0];
        for (int i=1;i<word.length();i++){
            if (word[i]!=c){
               if (mp.find(c)==mp.end()){
                       mp[c]=freq;
               }
                else{
                    mp[c]+=(freq-1);
                }
                c=word[i];
                freq=1;
            }
            else{
                freq++;
            }
        }

        if (mp.find(c)==mp.end()){
            mp[c]=freq;
        }
        else{
            mp[c]+=(freq-1);
        }
        int ans=0;

        for (auto it:mp){
            int freq=it.second;
            while(freq>1){
                ans++;
                freq--;
            }
        }
        ans++;
        return ans;
    }
};