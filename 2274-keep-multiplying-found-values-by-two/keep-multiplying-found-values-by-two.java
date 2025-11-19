class Solution {
    public int findFinalValue(int[] nums, int original) {
        int[] vals=new int[1001];
        for (int num:nums) vals[num]=1;

        while(original<=1000 && vals[original]==1){
            original*=2;
        }
        return original;
    }
}