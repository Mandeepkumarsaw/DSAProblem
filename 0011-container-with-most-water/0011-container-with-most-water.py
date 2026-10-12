class Solution:
    def maxArea(self, height: list[int]) -> int:
        maxWater = 0
        lp, rp = 0, len(height) - 1

        while lp < rp:
            w = rp - lp
            ht = min(height[lp], height[rp])
            currWater = w * ht
            maxWater = max(maxWater, currWater)

            if height[lp] < height[rp]:
                lp += 1
            else:
                rp -= 1

        return maxWater
        