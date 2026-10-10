class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        if len(nums) <= 2:
            if len(nums) ==2 and nums[0]==nums[1]:
                return True
            elif len(nums) <= 1:
                return False    
        nums.sort()

        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                return True
        return False                
        