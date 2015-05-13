class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        if nums and len(nums):
            li = [0]*len(nums)
            for (i, n) in enumerate(nums):
                if i:
                    li[i] = max(nums[i]+li[i-2], li[i-1])
                else:                     # i == 0
                    li[i] = nums[i]
            return li[-1]
        else:
            return 0

# sol = Solution()
# print sol.rob([11, 14, 17, 2])
