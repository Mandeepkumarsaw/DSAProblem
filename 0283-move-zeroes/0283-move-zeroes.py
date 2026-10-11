class Solution(object):
    def moveZeroes(self, nums):
        n=len(nums)
        prev = 0

        for i in range(n):
            
            if nums[i] != 0:
                nums[prev] = nums[i]
                
                if i != prev:
                    nums[i] = 0

                prev += 1    
         




        