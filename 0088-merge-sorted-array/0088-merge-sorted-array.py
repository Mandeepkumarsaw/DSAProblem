class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        p=m-1
        q=n-1
        i=m+n-1

        while q>=0:
            if p>=0 and nums1[p] > nums2[q]:
                nums1[i] = nums1[p]
                i-=1
                p-=1
            else:
                nums1[i] = nums2[q]
                i-=1
                q-=1

        