# わからないわ m(_-_)m

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def tose(self, leaf, val):
        return val*(10**len(str(leaf)))+int(leaf)
    
    # @param {TreeNode} root
    # @return {integer}
    def sumNumbers(self, root):
        if root:
            if root.left and root.right:
                return self.tose(root.left, root.val)+self.tose(root.right, root.val)
            elif root.left:
                return self.tose(root.left, root.val)
            elif root.right:
                return self.tose(root.right, root.val)
            else:
                return root.val
        else:
            return 0

root = TreeNode(1)
sol = Solution()
print sol.sumNumbers(root)
root.left = 2
root.right = 3
print sol.sumNumbers(root)
