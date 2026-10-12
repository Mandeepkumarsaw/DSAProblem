class Solution:
    def thirdMax(self, nums: list[int]) -> int:
        s = set()

        for ch in nums:
            s.add(ch)

            if len(s) > 3:
                s.remove(min(s))
        return min(s) if len(s) == 3 else max(s)        
        