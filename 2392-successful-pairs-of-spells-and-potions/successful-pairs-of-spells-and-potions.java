class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int n=spells.length;
        int m=potions.length;
        int[] ans=new int[n];

        for (int i=0;i<n;i++){
              long target=(success+spells[i]-1)/spells[i];
              int idx=helper(potions,target);
              ans[i]=m-idx;
        }
        return ans;
        
    }

    int helper(int[] potions,long target){
        int ans=0;
        int l=0,r=potions.length-1;
        while(l<=r){
            int mid=(l+r)/2;
            if (potions[mid]>=target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
}