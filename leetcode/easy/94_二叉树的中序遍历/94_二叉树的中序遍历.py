# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

#递归
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def inorder(node):
            if not node:
                return []
            return inorder(node.left) + [node.val] + inorder(node.right)
        
        return inorder(root)



#迭代
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        stack = []
        curr = root
        
        while curr or stack:
            # 遍历到最左边的节点
            while curr:
                stack.append(curr)
                curr = curr.left
            # 访问节点
            curr = stack.pop()
            res.append(curr.val)
            # 处理右子树
            curr = curr.right
            
        return res



#Morris遍历
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        curr = root
        
        while curr:
            if not curr.left:
                # 如果没有左子节点，访问当前节点并转向右子节点
                res.append(curr.val)
                curr = curr.right
            else:
                # 找到当前节点的前驱节点
                pre = curr.left
                while pre.right and pre.right != curr:
                    pre = pre.right
                
                if not pre.right:
                    # 建立临时链接
                    pre.right = curr
                    curr = curr.left
                else:
                    # 断开临时链接，访问当前节点
                    pre.right = None
                    res.append(curr.val)
                    curr = curr.right
        
        return res