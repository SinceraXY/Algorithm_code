# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy_head = ListNode(0)  # 设置一个虚拟头结点
        dummy_head.next = head    # 将虚拟头结点指向head，这样方便后面做删除操作
        cur = dummy_head
        while cur.next is not None:
            if cur.next.val == val:
                cur.next = cur.next.next  # 删除cur.next节点
            else:
                cur = cur.next
        return dummy_head.next