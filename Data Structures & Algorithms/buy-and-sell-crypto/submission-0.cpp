class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int costPrice = INT32_MAX, sellPrice = INT32_MIN, profit = 0;
        for (int price: prices) {
            if (price < costPrice) {
                costPrice = price;
                sellPrice = price; 
            }
            if (sellPrice < price) {
                sellPrice = price;
            }
            profit = max(profit, sellPrice - costPrice);
        }
        return profit;
    }
};
