class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxiAns=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
             if(matrix[i][j]=='1'){
                height[j]++;
             }
             else{
                height[j]=0;
             }
           }
           maxiAns=max(maxiAns,helper(height));
        }
        return maxiAns;
    }
    int helper(vector<int>&height){
        int n=height.size();
        stack<int>s;
        int left[n];
        int right[n];
        for(int i=0;i<n;i++){
            while(!s.empty()&& height[s.top()]>=height[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=-1;
            }
            else{
                left[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
         for(int i=n-1;i>=0;i--){
            while(!s.empty()&& height[s.top()]>=height[i]){
                s.pop();
            }
            if(s.empty()){
                right[i]=n;
            }
            else{
                right[i]=s.top();
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int area=height[i]*(right[i]-left[i]-1);
            ans=max(area,ans);
        }
        return ans;
    }
};