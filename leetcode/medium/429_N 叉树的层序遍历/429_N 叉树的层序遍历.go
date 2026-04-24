/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func levelOrder(root *Node) [][]int {
    if root == nil {
        return [][]int{}
    }
    ans := [][]int{}
    q := []*Node{root}
    for q != nil {
        level := []int{}
        tmp := q
        q = nil
        for _, node := range tmp {
            level = append(level, node.Val)
            q = append(q, node.Children...)
        }
        ans = append(ans, level)
    }
    return ans
}