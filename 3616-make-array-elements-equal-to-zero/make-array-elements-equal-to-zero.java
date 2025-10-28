class Solution {
    public int countValidSelections(int[] nums) {
         int n=nums.length;
         int ans=0;

         int cnt=0;

         for (int num:nums){
            if (num>0) cnt++;
         }
         
         if (cnt==0) return 2*n;

         for (int i=0;i<n;i++){
            int num=nums[i];
            if (num==0){
                int[] temp=Arrays.copyOf(nums,n);
                if (helper(temp,i,-1,cnt)==true) ans++;
                temp=Arrays.copyOf(nums,n);
                if (helper(temp,i,1,cnt)==true) ans++;
            }
         }
         return ans;
    }

    public boolean helper(int[] nums,int j,int dir,int nonzeros){
        int i=j+dir;
        while(nonzeros>0 && i>=0 && i<nums.length){
            if (nums[i]>0){
                nums[i]-=1;
                if (nums[i]==0) nonzeros--;
                dir*=-1;
            }
            i+=dir;
        }
        return nonzeros==0;
    }
}