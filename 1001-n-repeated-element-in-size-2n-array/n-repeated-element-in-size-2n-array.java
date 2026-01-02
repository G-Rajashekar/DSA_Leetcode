class Solution {
    public int repeatedNTimes(int[] nums) {
        Set<Integer>st=new HashSet<>();
        int n=nums.length;

        for (int num:nums){
            if (!st.contains(num)) st.add(num);
            else return num;
        }
        return -1;
    }
}