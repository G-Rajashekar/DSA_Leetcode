class Solution {
    public int countCollisions(String directions) {
        int n=directions.length();
        int l=0,r=n-1;

        while(l<n && directions.charAt(l)=='L') l++;
        while(r>=0 && directions.charAt(r)=='R') r--;

        int ans=0;

        for (int i=l;i<=r;i++){
            char ch=directions.charAt(i);
            if (ch!='S') ans++;
        }
        return ans;
    }
}