class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if nums[i] == 0:
                nums[i] = -1

        curr = 0
        max_len = 0
        seen = {0:-1}  #sum,idx

        for i in range(len(nums)):
            curr += nums[i]

            if curr in seen:
                length = seen[curr]  #pos/idx of sum(same as curr ele)
                max_len = max(max_len,i-length) #i is always ahead of prev idx(stored in map) bcz we iteration 0 to n using for loop

            else:
                seen[curr] = i

        return max_len

