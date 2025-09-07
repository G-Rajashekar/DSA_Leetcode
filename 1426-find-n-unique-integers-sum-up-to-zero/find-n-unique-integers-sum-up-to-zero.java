class Solution {
    public int[] sumZero(int n) {
        int[] ans=new int[n];
        int end=n/2;
        int ind=0;
        
        for (int i=1;i<=end;i++){
            ans[ind++]=i;
            ans[ind++]=-i;
        }
        if (n%2==1) ans[ind]=0; 
        return ans;
    }
}