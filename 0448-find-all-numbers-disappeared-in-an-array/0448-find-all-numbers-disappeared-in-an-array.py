class Solution:
    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
        n = len(nums)

        fset = set(range(1,n+1))
        nset = set(nums)

        return list(fset-nset)

           
        