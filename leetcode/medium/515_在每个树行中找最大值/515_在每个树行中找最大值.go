/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//深度优先搜索
func largestValues(root *TreeNode) (ans []int) {
    var dfs func(*TreeNode, int)
    dfs = func(node *TreeNode, curHeight int) {
        if node == nil {
            return
        }
        if curHeight == len(ans) {
            ans = append(ans, node.Val)
        } else {
            ans[curHeight] = max(ans[curHeight], node.Val)
        }
        dfs(node.Left, curHeight+1)
        dfs(node.Right, curHeight+1)
    }
    dfs(root, 0)
    return
}

func max(a, b int) int {
    if b > a {
        return b
    }
    return a
}



//广度优先搜索
func largestValues(root *TreeNode) (ans []int) {
    if root == nil {
        return
    }
    q := []*TreeNode{root}
    for len(q) > 0 {
        maxVal := math.MinInt32
        tmp := q
        q = nil
        for _, node := range tmp {
            maxVal = max(maxVal, node.Val)
            if node.Left != nil {
                q = append(q, node.Left)
            }
            if node.Right != nil {
                q = append(q, node.Right)
            }
        }
        ans = append(ans, maxVal)
    }
    return
}

func max(a, b int) int {
    if b > a {
        return b
    }
    return a
}