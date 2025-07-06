class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();

        if (n1>n2) return false;

        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for (int i=0;i<n1;i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }

        int l=0;
        for (int r=n1;r<n2;r++){
            if (isMatch(freq1,freq2)) return true;

            freq2[s2[l]-'a']--;
            freq2[s2[r]-'a']++;
            l++;
        }

        return isMatch(freq1,freq2);
    }

    bool isMatch(vector<int>&freq1,vector<int>&freq2){
        for (int i=0;i<26;i++){
            if (freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
};