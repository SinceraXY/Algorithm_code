//双指针法
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func reverseList(head *ListNode) *ListNode {
    var temp *ListNode   // 保存cur的下一个节点
    cur := head
    var pre *ListNode
    for cur != nil {
        temp = cur.Next
        cur.Next = pre
        pre = cur
        cur = temp
    }
    return pre
}