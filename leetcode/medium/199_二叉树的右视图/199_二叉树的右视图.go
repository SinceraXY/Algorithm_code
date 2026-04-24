/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rightSideView(root *TreeNode) []int {
    res := []int{}
    if root == nil {
        return res
    }

    q := []*TreeNode{root}
    for len(q) > 0 {
        size := len(q)
        for i := 0; i < size; i++ {
            node := q[0]
            q = q[1:]
            if i == size-1 {
                res = append(res, node.Val)
            }
            if node.Left != nil {
                q = append(q, node.Left)
            }
            if node.Right != nil {
                q = append(q, node.Right)
            }
        }
    }
    return res
}