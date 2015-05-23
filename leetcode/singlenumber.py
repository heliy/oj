# AC 64ms

class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def singleNumber(self, nums):
        d = {}
        for i in nums:
            if i in d:
                d.pop(i)
            else:
                d[i] = 0
        return d.keys()[0]
