class Solution:
    # @param {integer} n
    # @return {string[]}
    def generateParenthesis(self, n):
        parenthesis = set(["()"])
        for i in range(2, n+1):
            items = list(parenthesis)
            parenthesis.clear()
            for item in items:
                l = len(item)
                for i in range(l):
                    parenthesis.add("("+item[0:i]+")"+item[i:l])
        return sorted(list(parenthesis))

# sol = Solution()
# print len(sol.generateParenthesis(4))
