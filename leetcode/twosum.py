class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        H = {}
        for (i, n) in enumerate(num):
            H[n] = i
        for (i, n) in enumerate(num):
            another = target - n
            if another in H:
                if H[another] == i:
                    continue
                return (i + 1, H[another] + 1)

