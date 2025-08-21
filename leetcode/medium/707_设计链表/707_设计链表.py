class MyLinkedList:
    # 定义链表节点类
    class LinkedNode:
        def __init__(self, val=0):
            self.val = val
            self.next = None

    def __init__(self):
        # 这里定义的头结点是一个虚拟头结点，注意不是真正的链表头结点
        self._dummy_head = self.LinkedNode(0)
        self._size = 0

    def get(self, index: int) -> int:
        # 注意index是从0开始的，第0个节点就是头结点
        if index >= self._size or index < 0:
            return -1
        
        cur = self._dummy_head.next
        while index > 0:
            cur = cur.next
            index -= 1
        return cur.val

    def addAtHead(self, val: int) -> None:
        new_node = self.LinkedNode(val)
        new_node.next = self._dummy_head.next
        self._dummy_head.next = new_node
        self._size += 1

    def addAtTail(self, val: int) -> None:
        new_node = self.LinkedNode(val)
        cur = self._dummy_head
        while cur.next is not None:
            cur = cur.next
        cur.next = new_node
        self._size += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self._size:
            return
        new_node = self.LinkedNode(val)
        cur = self._dummy_head
        while index > 0:
            cur = cur.next
            index -= 1
        new_node.next = cur.next
        cur.next = new_node
        self._size += 1

    def deleteAtIndex(self, index: int) -> None:
        # 注意index是从0开始的
        if index >= self._size or index < 0:
            return
        
        cur = self._dummy_head
        while index > 0:
            cur = cur.next
            index -= 1
        cur.next = cur.next.next
        self._size -= 1

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)