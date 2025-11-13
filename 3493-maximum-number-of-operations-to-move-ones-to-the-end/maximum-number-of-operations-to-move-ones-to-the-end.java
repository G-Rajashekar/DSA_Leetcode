class Solution {
    public int maxOperations(String s) {
        int n=s.length();
        int ans=0;
        int cnt=0;
        int i=0;
         while(i<n){
            if (s.charAt(i)=='0'){
                ans+=cnt;
                while(i<n && s.charAt(i)=='0'){
                    i++;
                }
            }
            else{
                cnt++;
                i++;
            }
        }
        return ans;
    }
}