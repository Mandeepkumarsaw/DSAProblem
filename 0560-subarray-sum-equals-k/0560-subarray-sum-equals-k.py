class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixSum = 0
        ans = 0

        freq = defaultdict(int)
        freq[0] = 1

        for i in nums:
            prefixSum += i
            need  = prefixSum - k

            ans += freq[need]
            freq[prefixSum] += 1

        return ans    


        