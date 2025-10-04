class Solution {
    public int maxArea(int[] height) {
        int n=height.length;
        int ans=Integer.MIN_VALUE;

        int l=0,r=n-1;
        while(l<r){
            int hei=Math.min(height[l],height[r]);
            int len=r-l;
            ans=Math.max(ans,hei*len);
            if (height[l]<=height[r]) l++;
            else r--;
        }
        return ans;
    }
}