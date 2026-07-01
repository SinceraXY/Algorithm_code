/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//递归
func getNodesNum(cur *TreeNode) int {
	if cur == nil {
		return 0
	}
	leftNum := getNodesNum(cur.Left)
	rightNum := getNodesNum(cur.Right)
	treeNum := leftNum + rightNum + 1
	return treeNum
}

func countNodes(root *TreeNode) int {
	return getNodesNum(root)
}



//迭代法
func countNodes(root *TreeNode) int {
	que := []*TreeNode{}
	if root != nil {
		que = append(que, root)
	}

	result := 0
	for len(que) > 0 {
		size := len(que)
		for i := 0; i < size; i++ {
			node := que[0]
			que = que[1:]
			result++
			if node.Left != nil {
				que = append(que, node.Left)
			}
			if node.Right != nil {
				que = append(que, node.Right)
			}
		}
	}
	return result
}