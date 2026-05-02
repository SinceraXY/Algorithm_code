# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

#深度优先搜索
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        def dfs(node: TreeNode, curHeight: int) -> None:
            if node is None:
                return
            if curHeight == len(ans):
                ans.append(node.val)
            else:
                ans[curHeight] = max(ans[curHeight], node.val)
            dfs(node.left, curHeight + 1)
            dfs(node.right, curHeight + 1)
        dfs(root, 0)
        return ans



#广度优先搜索
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []
        ans = []
        q = [root]
        while q:
            maxVal = -inf
            tmp = q
            q = []
            for node in tmp:
                maxVal = max(maxVal, node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(maxVal)
        return ans