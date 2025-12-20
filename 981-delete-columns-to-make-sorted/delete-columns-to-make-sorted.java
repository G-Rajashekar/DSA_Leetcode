class Solution {
    public int minDeletionSize(String[] strs) {
        int n=strs.length;
        int ans=0;

        for (int c=0;c<strs[0].length();c++){
            boolean flag=true;
            for (int r=1;r<n;r++){
                if (strs[r].charAt(c)<strs[r-1].charAt(c)){
                    flag=false;
                    break;
                }
            }
            if (!flag) ans++;
        }
        return ans;
    }
}