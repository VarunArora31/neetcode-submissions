class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int costPrice = INT32_MAX, profit = 0;
        for (int price: prices) {
            costPrice = min(costPrice, price);
            profit = max(profit, price - costPrice);
        }
        return profit;
    }
};
