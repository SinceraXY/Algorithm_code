"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

#递归法
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root is None:
            return 0

        depth = 0
        for child in root.children:
            depth = max(depth, self.maxDepth(child))
        return depth + 1



#迭代法
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root is None:
            return 0

        depth = 0
        que = [root]
        while que:
            size = len(que)
            depth += 1
            for _ in range(size):
                node = que.pop(0)
                for child in node.children:
                    que.append(child)
        return depth