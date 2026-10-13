class Solution:
    def threeSumClosest(self, nums: list[int], target: int) -> int:
        nums.sort()
        n=len(nums)

        closest = nums[0]+nums[1]+nums[2]

        for k in range(0,n-2):
            l=k+1
            r=n-1

            while(l<r):
                csum = nums[k]+nums[l]+nums[r]

                if(abs(target-csum) < abs(target-closest)):
                    closest = csum
                if(csum < target):
                    l+=1
                else:
                    r-=1
        return closest                    
        