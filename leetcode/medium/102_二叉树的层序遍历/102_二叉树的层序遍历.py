# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# 方法一：迭代（使用队列）
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        
        res = []
        queue = collections.deque([root])
        
        while queue:
            level_size = len(queue)
            current_level = []
            for _ in range(level_size):
                node = queue.popleft()
                current_level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.append(current_level)
            
        return res

# 方法二：递归（深度优先搜索）
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        
        def dfs(node, level):
            if not node:
                return
            
            # 如果结果列表长度等于当前层数，说明是第一次进入该层，需要初始化
            if len(res) == level:
                res.append([])
            
            res[level].append(node.val)
            
            if node.left:
                dfs(node.left, level + 1)
            if node.right:
                dfs(node.right, level + 1)
                
        dfs(root, 0)
        return res