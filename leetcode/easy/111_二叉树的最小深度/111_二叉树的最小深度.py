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

        if node.left is None and node.right is not None:
            return 1 + rightDepth
        if node.left is not None and node.right is None:
            return 1 + leftDepth

        result = 1 + min(leftDepth, rightDepth)
        return result

    def minDepth(self, root: Optional[TreeNode]) -> int:
        return self.getDepth(root)



#迭代法
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        depth = 0
        que = [root]
        while que:
            size = len(que)
            depth += 1
            flag = 0
            for _ in range(size):
                node = que.pop(0)
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
                if not node.left and not node.right:
                    flag = 1
                    break
            if flag == 1:
                break
        return depth