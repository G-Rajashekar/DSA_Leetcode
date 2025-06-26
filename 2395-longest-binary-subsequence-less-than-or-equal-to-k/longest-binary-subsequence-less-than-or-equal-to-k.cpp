class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cnt=0;
        int n=s.length();
        long long value=0;
        long long base=1;
        for (int i=0;i<n;i++){
            if (s[i]=='0') cnt++;
        }

        for (int i=n-1;i>=0;i--){
            if ((n-i-1)>=32) break;
            if (s[i]=='1') {
                value+=base;
                if (value<=k) cnt++;
                else break;
            }
            base*=2;
        }
        return cnt;
    }
};
