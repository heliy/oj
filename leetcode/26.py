#coding:UTF-8

# AC, 100ms

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = 0
        for (i, num) in enumerate(nums):
            if n == 0 or nums[i-1] != num:
                nums[n] = num
                n += 1
        return n
