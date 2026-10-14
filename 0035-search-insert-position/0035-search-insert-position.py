class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        st = 0
        end = len(nums)-1
        found = False

        while st <= end:
            mid = st + (end - st) // 2

            if nums[mid] == target:
                found = True
                return mid
               
            elif nums[mid] > target:
                end = mid - 1
            else:
                st = mid + 1

        # if not Found:
        return st
        # else:
        #     return                              
                               
        