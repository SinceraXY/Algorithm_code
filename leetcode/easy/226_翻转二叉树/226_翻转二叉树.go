/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//递归法
func invertTree(root *TreeNode) *TreeNode {
    if root == nil {
        return root
    }
    root.Left, root.Right = root.Right, root.Left
    invertTree(root.Left)
    invertTree(root.Right)
    return root
}



//迭代法（栈）
func invertTreeIter(root *TreeNode) *TreeNode {
    if root == nil {
        return root
    }
    st := []*TreeNode{root}
    for len(st) > 0 {
        node := st[len(st)-1]
        st = st[:len(st)-1]
        node.Left, node.Right = node.Right, node.Left
        if node.Right != nil {
            st = append(st, node.Right)
        }
        if node.Left != nil {
            st = append(st, node.Left)
        }
    }
    return root
}



//统一写法迭代法（标记法）
func invertTreeUnified(root *TreeNode) *TreeNode {
    st := []*TreeNode{}
    if root != nil {
        st = append(st, root)
    }
    for len(st) > 0 {
        node := st[len(st)-1]
        st = st[:len(st)-1]
        if node != nil {
            if node.Right != nil {
                st = append(st, node.Right)
            }
            if node.Left != nil {
                st = append(st, node.Left)
            }
            st = append(st, node)
            st = append(st, nil)
        } else {
            node = st[len(st)-1]
            st = st[:len(st)-1]
            node.Left, node.Right = node.Right, node.Left
        }
    }
    return root
}



//层序遍历（队列）
func invertTreeLevelOrder(root *TreeNode) *TreeNode {
    if root == nil {
        return root
    }
    q := []*TreeNode{root}
    for len(q) > 0 {
        node := q[0]
        q = q[1:]
        node.Left, node.Right = node.Right, node.Left
        if node.Left != nil {
            q = append(q, node.Left)
        }
        if node.Right != nil {
            q = append(q, node.Right)
        }
    }
    return root
}