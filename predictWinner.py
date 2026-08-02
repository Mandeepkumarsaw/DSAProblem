from typing import List 

class Solution:
    def solve(self, nums: List[int], i: int, j: int) -> int:
        if i > j:
            return 0
        if i == j:
            return nums[i]

        take_i = nums[i] + min(self.solve(nums, i+2, j), self.solve(nums, i+1, j-1))
        take_j = nums[j] + min(self.solve(nums, i, j-2), self.solve(nums, i+1, j-1))

        return max(take_i, take_j)

    def predictTheWinner(self, nums: List[int]) -> bool:
        t_score = sum(nums)
        p1 = self.solve(nums, 0, len(nums)-1)
        p2 = t_score - p1
        return p1 >= p2


if __name__ == "__main__":
    nums = [1, 5, 2]  
    sol = Solution()
    result = sol.predictTheWinner(nums)
    print("Can Player 1 win?", result)   

    nums2 = [1, 5, 233, 7]
    result2 = sol.predictTheWinner(nums2)
    print("Can Player 1 win?", result2)  
