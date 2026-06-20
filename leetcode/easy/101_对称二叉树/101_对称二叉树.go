/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 递归法
func isSymmetric(root *TreeNode) bool {
	var compare func(left *TreeNode, right *TreeNode) bool
	compare = func(left *TreeNode, right *TreeNode) bool {
		// 首先排除空节点的情况
		if left == nil && right != nil {
			return false
		} else if left != nil && right == nil {
			return false
		} else if left == nil && right == nil {
			return true
		}
		// 再排除数值不相同的情况
		if left.Val != right.Val {
			return false
		}

		// 数值相同才做递归，做下一层的判断
		outside := compare(left.Left, right.Right)
		inside := compare(left.Right, right.Left)
		return outside && inside
	}

	if root == nil {
		return true
	}
	return compare(root.Left, root.Right)
}



// 迭代法(使用队列)
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}

	que := []*TreeNode{root.Left, root.Right}
	for len(que) > 0 {
		leftNode := que[0]
		que = que[1:]
		rightNode := que[0]
		que = que[1:]

		if leftNode == nil && rightNode == nil {
			continue
		}
		if leftNode == nil || rightNode == nil || leftNode.Val != rightNode.Val {
			return false
		}

		que = append(que, leftNode.Left)
		que = append(que, rightNode.Right)
		que = append(que, leftNode.Right)
		que = append(que, rightNode.Left)
	}
	return true
}



// 迭代法(使用栈)
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}

	st := []*TreeNode{root.Left, root.Right}
	for len(st) > 0 {
		leftNode := st[len(st)-1]
		st = st[:len(st)-1]
		rightNode := st[len(st)-1]
		st = st[:len(st)-1]

		if leftNode == nil && rightNode == nil {
			continue
		}
		if leftNode == nil || rightNode == nil || leftNode.Val != rightNode.Val {
			return false
		}

		st = append(st, leftNode.Left)
		st = append(st, rightNode.Right)
		st = append(st, leftNode.Right)
		st = append(st, rightNode.Left)
	}
	return true
}