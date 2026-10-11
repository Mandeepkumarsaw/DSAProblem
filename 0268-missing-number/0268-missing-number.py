class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        n=len(nums)

        for i in range(n):
            res = res ^ i
            res = res ^ nums[i]

        res = res ^ n

        return res    
        