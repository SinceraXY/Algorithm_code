# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

#递归
class Solution:
    def getNodesNum(self, cur: Optional[TreeNode]) -> int:
        if cur is None:
            return 0
        leftNum = self.getNodesNum(cur.left)
        rightNum = self.getNodesNum(cur.right)
        treeNum = leftNum + rightNum + 1
        return treeNum

    def countNodes(self, root: Optional[TreeNode]) -> int:
        return self.getNodesNum(root)



#迭代法
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        que = []
        if root is not None:
            que.append(root)

        result = 0
        while que:
            size = len(que)
            for _ in range(size):
                node = que.pop(0)
                result += 1
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
        return result