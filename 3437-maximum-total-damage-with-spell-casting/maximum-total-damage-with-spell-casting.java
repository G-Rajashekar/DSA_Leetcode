class Solution {
    public long maximumTotalDamage(int[] power) {
        Map<Integer,Long>mp=new HashMap<>();

        for (int p:power){
            if (!mp.containsKey(p)){
                mp.put(p,(long)p);
            }
            else{
                 mp.put(p,(long)mp.get(p)+p);
            }
        }
        List<Integer>li=new ArrayList<>(mp.keySet());
        Collections.sort(li);
        int n=li.size();
        long[] dp=new long[n];

        for (int i=0;i<n;i++){
            long take=mp.get(li.get(i));

            int j=i-1;

            while(j>=0 && li.get(i)-li.get(j)<=2){
                j--;
            }

            if (j>=0){
                take+=dp[j];
            }
            dp[i]=Math.max(i>0?dp[i-1]:0,take);
        }
        return dp[n-1];
    }
}