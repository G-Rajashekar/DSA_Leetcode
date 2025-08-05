class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int ans=0;

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (baskets[j]<fruits[i] || baskets[j]==-1) continue;
                else{
                    baskets[j]=-1;
                    break;
                }
            }
        }

        for (int i=0;i<n;i++){
            if (baskets[i]!=-1) ans++;
        }
        return ans;
    }
};