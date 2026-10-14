class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:

        

        def left(nums,target):
            st,end=0,len(nums)-1
            ans = -1

            while st<=end:
                mid = (st+end)//2

                if nums[mid] == target:
                    ans = mid
                    end = mid-1
                elif nums[mid]<target:
                    st=mid+1
                else:
                    end=mid-1
            return ans

        def right(nums,target):
            st,end=0,len(nums)-1
            ans = -1

            while st<=end:
                mid = (st+end)//2

                if nums[mid] == target:
                    ans = mid
                    st = mid+1
                elif nums[mid]<target:
                    st=mid+1
                else:
                    end=mid-1
            return ans

        return [left(nums,target),right(nums,target)]                       


        