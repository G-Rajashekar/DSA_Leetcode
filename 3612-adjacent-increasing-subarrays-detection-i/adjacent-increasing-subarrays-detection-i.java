class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
          int n=nums.size();

          if (2*k>n) return false;

          for (int i=0;i<=n-2*k;i++){
            boolean flag1=true;

            for (int j=i+1;j<i+k;j++){
                if (nums.get(j)<=nums.get(j-1)) {
                    flag1=false;
                    break;
                }
            }
            if (flag1 ){
                boolean flag2=true;
                for (int j=i+k+1;j<i+2*k;j++){
                    if  (nums.get(j)<=nums.get(j-1)){
                        flag2=false;
                        break;
                    }
                }
                if (flag2) return true;
            }
          }

          return false;
    }
}