class Solution:
    def fourSum(self, nums: list[int], target: int) -> list[list[int]]:
        n = len(nums)
        ans = set()

        for i in range(n):
            for j in range(i+1,n):
                kset = set()
                for k in range(j+1,n):
                    ReqSum = target - nums[i] - nums[j] - nums[k]

                    if ReqSum in kset:
                        ans.add(tuple(sorted([nums[i],nums[j],nums[k],ReqSum])))

                    kset.add(nums[k])   

        return list(ans)
        