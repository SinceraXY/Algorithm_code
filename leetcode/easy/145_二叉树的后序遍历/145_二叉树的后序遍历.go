/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//递归
func postorderTraversal(root *TreeNode) []int {
    res := []int{}
    var postorder func(*TreeNode)
    postorder = func(node *TreeNode) {
        if node == nil {
            return
        }
        postorder(node.Left)
        postorder(node.Right)
        res = append(res, node.Val)
    }
    postorder(root)
    return res
}



//迭代
func postorderTraversal(root *TreeNode) []int {
    res := []int{}
    stk := []*TreeNode{}
    var prev *TreeNode
    for root != nil || len(stk) > 0 {
        for root != nil {
            stk = append(stk, root)
            root = root.Left
        }
        root = stk[len(stk)-1]
        stk = stk[:len(stk)-1]
        if root.Right == nil || root.Right == prev {
            res = append(res, root.Val)
            prev = root
            root = nil
        } else {
            stk = append(stk, root)
            root = root.Right
        }
    }
    return res
}



//Morris遍历
func reverse(a []int) {
    for i, n := 0, len(a); i < n/2; i++ {
        a[i], a[n-1-i] = a[n-1-i], a[i]
    }
}

func postorderTraversal(root *TreeNode) []int {
    res := []int{}
    addPath := func(node *TreeNode) {
        resSize := len(res)
        for ; node != nil; node = node.Right {
            res = append(res, node.Val)
        }
        reverse(res[resSize:])
    }

    p1 := root
    for p1 != nil {
        if p2 := p1.Left; p2 != nil {
            for p2.Right != nil && p2.Right != p1 {
                p2 = p2.Right
            }
            if p2.Right == nil {
                p2.Right = p1
                p1 = p1.Left
                continue
            }
            p2.Right = nil
            addPath(p1.Left)
        }
        p1 = p1.Right
    }
    addPath(root)
    return res
}