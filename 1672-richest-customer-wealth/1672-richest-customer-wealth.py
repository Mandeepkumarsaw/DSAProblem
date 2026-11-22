class Solution:
    def maximumWealth(self, accounts: list[list[int]]) -> int:
        n=len(accounts)
        ans=0
        for i in accounts:
            ans=max(ans,sum(i))
        return ans

        