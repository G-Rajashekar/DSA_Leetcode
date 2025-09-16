class Solution {
    public static int gcd(int a,int b){
        return b==0?a:gcd(b,a%b);
    }
    public List<Integer> replaceNonCoprimes(int[] nums) {
        ArrayList<Integer>res=new ArrayList<>();

        for (int num:nums){
            while(!res.isEmpty()){
                int prev=res.get(res.size()-1);
                int cur=num;

                int GCD=gcd(prev,cur);
                if (GCD==1) {
                    break;
                }
                res.remove(res.size()-1);
                long val=(long)(prev/GCD)*cur;
                num=(int)val;
            }
            res.add(num);
        }
        return res;
            
    }
}