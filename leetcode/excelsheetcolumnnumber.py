# AC 88ms

class Solution:
    # @param {string} s
    # @return {integer}
    def titleToNumber(self, s):
        n = 0
        for i in s:
            n = n*26 + int( ord(i) - ord('A')+1)
        return n

# sol = Solution()
# print sol.titleToNumber("AB")
# print sol.titleToNumber("B")
