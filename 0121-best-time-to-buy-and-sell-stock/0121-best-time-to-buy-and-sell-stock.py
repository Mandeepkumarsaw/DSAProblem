class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        bestbuy = prices[0]
        profit = 0

        for i in range(1,len(prices)):
            if prices[i] > bestbuy:
                profit = max(profit,prices[i]-bestbuy) 

            bestbuy= min(bestbuy,prices[i])
        return profit    
        