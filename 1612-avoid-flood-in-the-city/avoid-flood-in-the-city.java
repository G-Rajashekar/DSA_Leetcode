class Solution {
    public int[] avoidFlood(int[] rains) {
        int n=rains.length;
        TreeSet<Integer>st=new TreeSet<>();
        Map<Integer,Integer>mp=new HashMap<>();

        int[] ans=new int[n];
        Arrays.fill(ans,1);
        for (int i=0;i<n;i++){
            if (rains[i]==0){
                st.add(i);
            }
            else{
                ans[i]=-1;

                if (mp.containsKey(rains[i])){
                    Integer dryDay=st.higher(mp.get(rains[i]));
                    if (dryDay==null) return new int[0];
                    ans[dryDay]=rains[i];
                    st.remove(dryDay);
                }
                mp.put(rains[i],i);
            }
        }
        return ans;
    }
}