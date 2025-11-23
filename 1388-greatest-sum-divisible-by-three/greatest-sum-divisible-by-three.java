class Solution {
    public int maxSumDivThree(int[] nums) {
        int n=nums.length;
        int sum=0;
        List<Integer>r1=new ArrayList<>();
        List<Integer>r2=new ArrayList<>();

        for (int num:nums){
            sum+=num;
            if (num%3==1){
                r1.add(num);
            }
            else if (num%3==2){
                r2.add(num);
            }
        }

        if (sum%3==0) return sum;

        Collections.sort(r1);
        Collections.sort(r2);
        if (sum%3==1){
            int remove1=Integer.MAX_VALUE;
            if (r1.size()>=1) remove1=r1.get(0);
            int remove2=Integer.MAX_VALUE;
            if (r2.size()>=2) remove2=r2.get(0)+r2.get(1);

            sum=sum-Math.min(remove1,remove2);
        }
        else{
            int remove1=Integer.MAX_VALUE;
            if (r1.size()>=2) remove1=r1.get(0)+r1.get(1);
            int remove2=Integer.MAX_VALUE;
            if (r2.size()>=1) remove2=r2.get(0);

            sum=sum-Math.min(remove1,remove2);
        }
        return Math.max(sum,0);

    }
}