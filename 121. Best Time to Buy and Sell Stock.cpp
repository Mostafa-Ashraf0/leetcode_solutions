class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = prices[0];
        int profit = 0;
        int newProfit;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < minP){
                minP = prices[i];
            }
            newProfit = prices[i] - minP;
            if(newProfit>profit){
                profit = newProfit;
            }
        }
        return profit;
    }
};