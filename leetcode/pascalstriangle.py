class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
        if numRows == 0:
            return []
        if numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1], [1, 1]]
        lists = [[1], [1, 1]]
        for i in xrange(2, numRows):
            m = lists[-1]
            l = [1]
            for i in xrange(1, i):
                l.append(m[i-1]+m[i])
            l.append(1)
            lists.append(l)
        return lists

sol = Solution()
print sol.generate(1)
print sol.generate(5)
