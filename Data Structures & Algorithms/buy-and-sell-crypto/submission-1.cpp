class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy=INT_MAX;
        int minBuyIndex=0;
        int maxSell=0;
        int maxSellIndex=0;
        int maxProfit=0;
        for (int i=0;i<prices.size();i++){
            if (minBuy>prices[i]){
                minBuy=prices[i];
            }
            else maxProfit=std::max(maxProfit, prices[i]-minBuy);
        }

        return maxProfit;
    }
};
