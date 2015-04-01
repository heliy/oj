class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        alphes = {}
        maxlen = begin =  0;
        for (index, letter) in enumerate(s):
            # find the len of the longest string ends in idex
            if letter in alphes and alphes[letter] >= begin:
                begin = alphes[letter] + 1
            alphes[letter] = index
            maxlen = max(maxlen, index-begin+1)
        return maxlen

# sol = Solution()
# print sol.lengthOfLongestSubstring("ddddd")
# print sol.lengthOfLongestSubstring("abcabcbb")
