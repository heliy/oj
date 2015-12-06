class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if len(nums) == 0:
            return []
        mae = nums[0]
        l = []
        for (i, num) in enumerate(nums):
            if i == 0:
                l = [str(mae)]
            elif nums[i-1] == num-1:
                l[-1] = "%d->%d" % (mae, num)
            else:
                l.append(str(num))
                mae = num
        return l
