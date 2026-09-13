class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount<1:
            return 0

        minCoins = [float('inf')] * (amount+1)    
        minCoins[0] = 0   #coins to make zero is 0

        for i in range(1,amount+1):
            for coin in coins:
                if coin <= i:
                    minCoins[i] = min(minCoins[i],1+minCoins[i-coin])

        return -1 if minCoins[amount] == float('inf') else minCoins[amount]        
        