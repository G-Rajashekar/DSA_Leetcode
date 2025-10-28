class Solution {
    public int countValidSelections(int[] nums) {
        int n=nums.length;

        int[] prefix=new int[n];

        prefix[0]=nums[0];

        for (int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        int ans=0;

        for (int i=0;i<n;i++){
            if (nums[i]==0){
               int left,right;
               if (i==0) {
                   left=0;
                   right=prefix[n-1]-nums[0];
               }
               else if (i==n-1){
                    left=prefix[n-1]-nums[n-1];
                    right=0;
               }
               else{
                   left=prefix[i-1];
                   right=prefix[n-1]-left;
               }
                
                if (left==right) ans+=2;
                else{
                    if ((right-left)<=1 && right>left) ans++;
                    if ((left-right)<=1 && left>right) ans++;
                }

            }
        }
        return ans;
    }
}