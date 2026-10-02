# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Definition for a binary tree node.

class Solution:
    def helper(self, nums, st, end):
        if st > end:
            return None

        mid = st + (end - st) // 2
        root = TreeNode(nums[mid])

        root.left = self.helper(nums, st, mid - 1)
        root.right = self.helper(nums, mid + 1, end)

        return root

    def sortedArrayToBST(self, nums):
        return self.helper(nums, 0, len(nums) - 1)
