# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

#递归法
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def compare(left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
            # 首先排除空节点的情况
            if left is None and right is not None:
                return False
            elif left is not None and right is None:
                return False
            elif left is None and right is None:
                return True
            # 再排除数值不相同的情况
            elif left.val != right.val:
                return False

            # 数值相同才做递归，做下一层的判断
            outside = compare(left.left, right.right)
            inside = compare(left.right, right.left)
            return outside and inside

        if root is None:
            return True
        return compare(root.left, root.right)



# 迭代法(使用队列)
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        que = [root.left, root.right]
        while que:
            leftNode = que.pop(0)
            rightNode = que.pop(0)

            if leftNode is None and rightNode is None:
                continue
            if leftNode is None or rightNode is None or leftNode.val != rightNode.val:
                return False

            que.append(leftNode.left)
            que.append(rightNode.right)
            que.append(leftNode.right)
            que.append(rightNode.left)
        return True



# 迭代法(使用栈)
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        st = [root.left, root.right]
        while st:
            leftNode = st.pop()
            rightNode = st.pop()

            if leftNode is None and rightNode is None:
                continue
            if leftNode is None or rightNode is None or leftNode.val != rightNode.val:
                return False

            st.append(leftNode.left)
            st.append(rightNode.right)
            st.append(leftNode.right)
            st.append(rightNode.left)
        return True