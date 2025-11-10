class Solution {
    public int minOperations(int[] nums) {
        Stack<Integer>s=new Stack<>();
        int res=0;

        for (int a:nums){
            while(!s.empty() && s.peek()>a) s.pop();
            if (a==0) continue;

            if (s.empty() ||  s.peek()<a){
                res++;
                s.push(a);
            }
        }
        return res;
    }
}