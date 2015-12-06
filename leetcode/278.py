# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        def __find(p, q):
            if p == q:
                return p
            mid = int((p + q)/2)
            if isBadVersion(mid):
                if mid == 0 or not isBadVersion(mid-1):
                    return mid
                return __find(p, mid-1)
            else:
                return __find(mid+1, q)
        return __find(0, n)
                
