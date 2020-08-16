class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int first_buy = INT_MIN,second_buy = INT_MIN;
        int first_sold = 0,second_sold=0;
        
        for(int i=0;i<prices.size();i++){
            first_buy = max(first_buy, -prices[i]);
            first_sold = max(first_sold, first_buy+ prices[i]);
            second_buy = max(second_buy, first_sold-prices[i]);
            second_sold = max(second_sold, second_buy+ prices[i]);
        }
        return second_sold;
    }
};
