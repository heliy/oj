class Solution:
    # @return a string
    def convert(self, s, nRows):
    if nRows == 1:
        return s
    down = True
    strings = [""] * nRows
    # go through the string and append letters one by one    lpos = 0
    for letter in s:
        strings[lpos] += letter
        if lpos == nRows - 1:
            lpos -= 1
            down = False
        elif lpos == 0:
            lpos = 1
            down = True
        elif down:
            lpos += 1
        else:
            lpos -= 1
    return "".join(strings)

sol = Solution()
sol.convert("PAYPALISHIRING", 3)
