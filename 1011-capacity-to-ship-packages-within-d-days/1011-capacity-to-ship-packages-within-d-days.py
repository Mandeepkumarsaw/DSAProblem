class Solution:
    def isPossible(self,weights,days,mid):
        Within = 1   #Start from day1
        Wsum = 0    

        for el in weights:
            if Wsum+el <= mid:  #if less than or equal,we take it as possible sol 
                Wsum += el
            else:
                Within += 1   #Increase days
                Wsum = el

                if Within > days:
                    return False
        return True            


    def shipWithinDays(self, weights: List[int], days: int) -> int:
        if len(weights) < days:
            return -1

        low = max(weights)
        high = sum(weights)
        ans = high

        while low <= high:
            mid = low + (high-low)//2

            if self.isPossible(weights,days,mid):
                ans = mid
                high = mid-1
            else:
                low = mid+1

        return ans            
        