class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        int n=nums.length;
        HashMap<Integer,Integer>mp=new HashMap<>();

        for (int num:nums){
            int rem=((num%value)+value)%value;
            if (mp.containsKey(rem)){
                mp.put(rem,mp.get(rem)+1);
            }
            else{
                mp.put(rem,1);
            }
        }

        int mex=0;

        while(mp.containsKey(mex%value) && mp.get(mex%value)>0){
            mp.put(mex%value,mp.get(mex%value)-1);
            mex++;
        }
        return mex;
    }
}