# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

#递归法
class Solution:
    def getDepth(self, node: Optional[TreeNode]) -> int:
        if node is None:
            return 0
        leftDepth = self.getDepth(node.left)
        rightDepth = self.getDepth(node.right)
        depth = 1 + max(leftDepth, rightDepth)
        return depth

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.getDepth(root)



#迭代法
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        depth = 0
        que = [root]
        while que:
            size = len(que)
            depth += 1
            for _ in range(size):
                node = que.pop(0)
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
        return depth