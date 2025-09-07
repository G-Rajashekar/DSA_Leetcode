class Solution {
    public int[] sumZero(int n) {
        int[] ans=new int[n];

        int start=-n/2;
        int end=n/2;
        int ind=0;
        if (n%2==1){
              for (int i=start;i<=end;i++){
                ans[ind++]=i;
              }
        }
        else{
            for (int i=start;i<=end;i++){
                if (i!=0){
                    ans[ind++]=i;
                }
            }
        }
        return ans;
    }
}