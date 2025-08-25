/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

//哈希表法
func detectCycle(head *ListNode) *ListNode {
    visited := make(map[*ListNode]bool)
    for head != nil {
        if visited[head] {
            return head
        }
        visited[head] = true
        head = head.Next
    }
    return nil
}



//快慢指针法
func detectCycle(head *ListNode) *ListNode {
    fast := head
    slow := head
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
        if slow == fast {
            index1 := fast
            index2 := head
            for index1 != index2 {
                index1 = index1.Next
                index2 = index2.Next
            }
            return index2
        }
    }
    return nil
}