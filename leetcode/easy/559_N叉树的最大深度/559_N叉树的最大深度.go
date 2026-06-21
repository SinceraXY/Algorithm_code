/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

//递归法
func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}

	depth := 0
	for _, child := range root.Children {
		childDepth := maxDepth(child)
		if childDepth > depth {
			depth = childDepth
		}
	}
	return depth + 1
}



//迭代法
func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}

	depth := 0
	que := []*Node{root}
	for len(que) > 0 {
		size := len(que)
		depth++
		for i := 0; i < size; i++ {
			node := que[0]
			que = que[1:]
			for _, child := range node.Children {
				que = append(que, child)
			}
		}
	}
	return depth
}