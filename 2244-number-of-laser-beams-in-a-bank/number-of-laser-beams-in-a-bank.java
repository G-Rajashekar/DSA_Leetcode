class Solution {
    public int numberOfBeams(String[] bank) {
        int ans=0,prev=0;

        for(String row:bank){
            int cur=0;

            for (char ch:row.toCharArray()){
                if (ch=='1') cur++;
            }
            if (cur>0){
                ans+=(cur*prev);
                prev=cur;
            }
        }
        return ans;
    }
}