class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int num1=-1;
        int num2=-1;
        HashSet<Integer>hset=new HashSet<>();
        
        for (int num:nums){
            if (!hset.contains(num)) hset.add(num);
            else {
                if (num1==-1) num1=num;
                else{
                    num2=num;
                    break;
                }
            }
        }
        int[] ans={num1,num2};

        return ans;
    }
}