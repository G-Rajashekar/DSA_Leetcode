class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;

        int i=0;
        int j=n-1;
        
        while(i<=j){
            int len=j-i;
            int area=len*min(height[i],height[j]);
            ans=max(ans,area);
            if (height[i]<=height[j]) i++;
            else j--;
        }
        return ans;
    }
};