class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<int>ans(m*n);

        int i=0,r=0,c=0,dir=1;

        while(r<n && c<m){
            ans[i]=mat[r][c];
            i++;

            int newR,newC;

            if (dir==1){
                newR=r-1;
                newC=c+1;
            }
            else{
                newR=r+1;
                newC=c-1;
            }

            if (newR>=0 && newR<n && newC>=0 && newC<m){
                r=newR;
                c=newC;
            }
            else{
                if (dir==1){
                    if (c<m-1) c++;
                    else r++;
                }
                else{
                    if (r<n-1) r++;
                    else c++;
                }
                dir=!dir;
            }
        }
        return ans;
    }
};