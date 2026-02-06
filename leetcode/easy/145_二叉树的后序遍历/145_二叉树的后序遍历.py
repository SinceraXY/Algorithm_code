# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

#递归
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def postorder(root: TreeNode):
            if not root:
                return
            postorder(root.left)
            postorder(root.right)
            res.append(root.val)
        
        res = list()
        postorder(root)
        return res



#迭代
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return list()
        
        res = list()
        stack = list()
        prev = None

        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if not root.right or root.right == prev:
                res.append(root.val)
                prev = root
                root = None
            else:
                stack.append(root)
                root = root.right
        
        return res



#Morris遍历
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def addPath(node: TreeNode):
            count = 0
            while node:
                count += 1
                res.append(node.val)
                node = node.right
            i, j = len(res) - count, len(res) - 1
            while i < j:
                res[i], res[j] = res[j], res[i]
                i += 1
                j -= 1
        
        if not root:
            return list()
        
        res = list()
        p1 = root

        while p1:
            p2 = p1.left
            if p2:
                while p2.right and p2.right != p1:
                    p2 = p2.right
                if not p2.right:
                    p2.right = p1
                    p1 = p1.left
                    continue
                else:
                    p2.right = None
                    addPath(p1.left)
            p1 = p1.right
        
        addPath(root)
        return res