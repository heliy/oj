# AC 76ms

class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def alphas(self, s):
        d = {}
        for (i, a) in enumerate(s):
            if a in d:
                d[a].append(i)
            else:
                d[a] = [i]
        # print d
        nums = {}
        for a in d:
            l = len(d[a])
            if l in nums:
                nums[l].append([a, d[a]])
            else:
                nums[l] = [[a, d[a]]]
        return nums

    def find(self, locs, als):
        # print locs
        for [b, ls] in als:
            # print ls
            if len(ls) != len(locs):
                continue
            for i in range(len(ls)):
                if locs[i] != ls[i]:
                    break
            else:
                return b
        return False
    
    def isIsomorphic(self, s, t):
        d1 = self.alphas(s)
        d2 = self.alphas(t)
        keys1 = d1.keys()
        keys2 = d2.keys()
        if len(keys1) != len(keys2):
            return False
        for key in keys1:
            if key not in d2:
                return False
            alphas1 = d1[key]
            alphas2 = d2[key]
            if len(alphas1) != len(alphas2):
                return False
            for [a, locs] in alphas1:
                b = self.find(locs, alphas2)
                # print a, b
                if b:
                    alphas2.remove([b, locs])
                else:
                    return False
        return True

# sol = Solution()
# s1 = "ab"
# s2 = "ca"
# print sol.alphas(s1)
# print sol.alphas(s2)
# print sol.isIsomorphic(s1, s2)
        
