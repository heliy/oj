class Solution:
    # @param m, an integer
    # @param n, an integer
    # @return an integer
    def uniquePaths(self, m, n):
        dp = [0]*(n)
        dp = [dp]*(m)
        for i in xrange(m):
            for j in xrange(n):
                if i == 0 or j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = dp[i-1][j]+dp[i][j-1]
        return dp[m-1][n-1]

# sol = Solution()
# print sol.uniquePaths(1, 2)
