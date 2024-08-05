class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lastBuy = INT_MAX;
        int res = 0;
        for(int i=0;i<prices.size();i++) {
            if (prices[i] < lastBuy) {
                lastBuy = prices[i];
            }      
            res = max(res, prices[i]-lastBuy);
        }
        return res;
    }
};