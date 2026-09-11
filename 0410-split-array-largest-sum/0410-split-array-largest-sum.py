class Solution:
    def isPossible(self,nums,k,mid):
        split = 1
        Wsum = 0

        for el in nums:
            if Wsum+el <= mid:
                Wsum += el
            else:
                split += 1
                Wsum = el
                if split > k:
                    return False

        return True            
    def splitArray(self, nums: List[int], k: int) -> int:
        low = max(nums)
        high = sum(nums)
        ans = high

        while low <= high:
            mid = low + (high-low)//2

            if self.isPossible(nums,k,mid):
                ans = mid
                high = mid - 1
            else:
                low=mid+1
                
        return ans            
         
        