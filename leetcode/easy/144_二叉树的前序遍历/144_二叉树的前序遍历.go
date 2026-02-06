/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//递归
func preorderTraversal(root *TreeNode) []int {
    vals := []int{}
    var preorder func(*TreeNode)
    preorder = func(node *TreeNode) {
        if node == nil {
            return
        }
        vals = append(vals, node.Val)
        preorder(node.Left)
        preorder(node.Right)
    }
    preorder(root)
    return vals
}



//迭代
func preorderTraversal(root *TreeNode) []int {
    vals := []int{}
    stack := []*TreeNode{}
    node := root
    for node != nil || len(stack) > 0 {
        for node != nil {
            vals = append(vals, node.Val)
            stack = append(stack, node)
            node = node.Left
        }
        node = stack[len(stack)-1].Right
        stack = stack[:len(stack)-1]
    }
    return vals
}



//Morris遍历
func preorderTraversal(root *TreeNode) []int {
    vals := []int{}
    var p1, p2 *TreeNode = root, nil
    for p1 != nil {
        p2 = p1.Left
        if p2 != nil {
            for p2.Right != nil && p2.Right != p1 {
                p2 = p2.Right
            }
            if p2.Right == nil {
                vals = append(vals, p1.Val)
                p2.Right = p1
                p1 = p1.Left
                continue
            }
            p2.Right = nil
        } else {
            vals = append(vals, p1.Val)
        }
        p1 = p1.Right
    }
    return vals
}