class Solution {
    public int minimumDistance(int[] nums) {
        int n=nums.length;
        
        Map<Integer,List<Integer>>mp=new HashMap<>();

        int res=n;

        for (int i=0;i<n;i++){
            mp.putIfAbsent(nums[i],new ArrayList<>());

            mp.get(nums[i]).add(i);

            if (mp.get(nums[i]).size()>=3){
                List<Integer>li=mp.get(nums[i]);

                int siz=li.size();
                int j=li.get(siz-3);

                res=Math.min(res,i-j);
            }
        }


        return res>=n?-1:2*res;
    }
}