class Solution {
    public int repeatedNTimes(int[] nums) {
        Map<Integer,Integer>mp=new HashMap<>();
        int n=nums.length;

        for (int num:nums){
            if (!mp.containsKey(num)){
                mp.put(num,0);
            }
            mp.put(num,mp.get(num)+1);

            if (mp.get(num)==n/2) return num;
        }
        return -1;
    }
}