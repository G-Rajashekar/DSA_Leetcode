class Solution {
    public int countCollisions(String directions) {
        int n=directions.length();

        int ans=0;
        int l=0,r=0;

        for (int i=0;i<n;i++){
            if (directions.charAt(i)=='R') r++;
            else{
                ans+=r;
                r=0;
            }
            if (directions.charAt(n-i-1)=='L') l++;
            else{
                ans+=l;
                l=0;
            }
        }
        return ans;
    }
}