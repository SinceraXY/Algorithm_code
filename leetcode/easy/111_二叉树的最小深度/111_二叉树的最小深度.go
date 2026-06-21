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

	if node.Left == nil && node.Right != nil {
		return 1 + rightDepth
	}
	if node.Left != nil && node.Right == nil {
		return 1 + leftDepth
	}

	if leftDepth < rightDepth {
		return 1 + leftDepth
	}
	return 1 + rightDepth
}

func minDepth(root *TreeNode) int {
	return getDepth(root)
}



//迭代法
func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	depth := 0
	que := []*TreeNode{root}
	for len(que) > 0 {
		size := len(que)
		depth++
		flag := 0
		for i := 0; i < size; i++ {
			node := que[0]
			que = que[1:]
			if node.Left != nil {
				que = append(que, node.Left)
			}
			if node.Right != nil {
				que = append(que, node.Right)
			}
			if node.Left == nil && node.Right == nil {
				flag = 1
				break
			}
		}
		if flag == 1 {
			break
		}
	}
	return depth
}