class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) {
            return 0;
        }
        
        int profit = 0, purchasePrice = prices[0], sellPrice = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(purchasePrice < prices[i]) {
                if(sellPrice < prices[i]) {
                    sellPrice = prices[i];
                } else {
                    profit += (sellPrice - purchasePrice);
                    purchasePrice = prices[i], sellPrice = 0;                    
                }
            } else {
                if(sellPrice != 0) {
                    profit += (sellPrice - purchasePrice);
                    sellPrice = 0;                        
                }
                purchasePrice = prices[i];
            }
        }
        
        if(sellPrice != 0) {
            profit += (sellPrice - purchasePrice);
        }
        
        return profit;
    }
};
