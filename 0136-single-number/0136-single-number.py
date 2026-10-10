class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        ans=0

        for el in nums:
            ans = ans ^ el
        return ans    