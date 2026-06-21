/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//递归法
func getDepth(node *TreeNode) int {
	if node == nil {
		return 0
	}
	leftDepth := getDepth(node.Left)
	rightDepth := getDepth(node.Right)
	if leftDepth > rightDepth {
		return leftDepth + 1
	}
	return rightDepth + 1
}

func maxDepth(root *TreeNode) int {
	return getDepth(root)
}



//迭代法
func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	depth := 0
	que := []*TreeNode{root}
	for len(que) > 0 {
		size := len(que)
		depth++
		for i := 0; i < size; i++ {
			node := que[0]
			que = que[1:]
			if node.Left != nil {
				que = append(que, node.Left)
			}
			if node.Right != nil {
				que = append(que, node.Right)
			}
		}
	}
	return depth
}