# Memory Limit Exceeded

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param {integer[]} preorder
    # @param {integer[]} inorder
    # @return {TreeNode}
    def buildTree(self, preorder, inorder):
        if len(preorder):
            root = preorder[0]
            index = inorder.index(root)
            node = TreeNode(root)
            node.left = self.buildTree(preorder[1:1+index], inorder[:index])
            node.right = self.buildTree(preorder[1+index:], inorder[1+index:])
            return node
        else:
            return None        

# pre = [3, 2, 1, 4, 5]
# ino = [1, 2, 3, 4, 5]
