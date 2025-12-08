class Solution {
    public int countTriples(int n) {
        HashSet<Integer>hset=new HashSet<>();


        for (int i=1;i<=n;i++) hset.add(i*i);

        int cnt=0;

        for (int i=1;i<=n;i++){
            int h=i*i;
            for (int j=1;j<i;j++){
                int s1=j*j;
                int s2=h-s1;
                if (hset.contains(s2)) cnt++;
            }

        }
        return cnt;
    }
}