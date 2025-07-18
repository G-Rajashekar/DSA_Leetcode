class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stock=prices[0];
        int profit=0;

        for (int i=1;i<prices.size();i++){
            if (prices[i]>stock){
                profit=max(profit,prices[i]-stock);
            }
            else{
                stock=min(stock,prices[i]);
            }
        }
        return profit;
    }
};