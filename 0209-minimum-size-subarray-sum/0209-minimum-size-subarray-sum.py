class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        
        curr=0
        left=0
        minLen=float('inf')

        for i in range(len(nums)):
            curr += nums[i]

            while curr >= target:
                minLen = min(minLen,i-left+1)
                curr -= nums[left]
                left += 1

        return 0 if minLen == float('inf') else minLen    

        
        