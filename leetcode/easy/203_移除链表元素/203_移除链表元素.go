/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func removeElements(head *ListNode, val int) *ListNode {
    dummyHead := &ListNode{Next: head}
    cur := dummyHead
    for cur.Next != nil {
        if cur.Next.Val == val {
            cur.Next = cur.Next.Next  // 删除cur.Next节点
        } else {
            cur = cur.Next
        }
    }
    return dummyHead.Next
}