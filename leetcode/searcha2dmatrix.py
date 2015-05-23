class Solution:
    # @param {integer[][]} matrix
    # @param {integer} target
    # @return {boolean}
    def searchMatrix(self, matrix, target):
        t = []
        for m in matrix:
            t.extend(m)
        return target in t
