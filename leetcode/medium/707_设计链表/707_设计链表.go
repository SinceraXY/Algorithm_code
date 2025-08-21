// 定义链表节点结构体
type LinkedNode struct {
    Val  int
    Next *LinkedNode
}

// MyLinkedList 设计链表
type MyLinkedList struct {
    dummyHead *LinkedNode // 这里定义的头结点是一个虚拟头结点，注意不是真正的链表头结点
    size      int
}

// Constructor 构造函数
func Constructor() MyLinkedList {
    return MyLinkedList{
        dummyHead: &LinkedNode{Val: 0, Next: nil},
        size:      0,
    }
}

// Get 获取链表中第 index 个节点的值。如果索引无效，则返回-1。
// 注意index是从0开始的，第0个节点就是头结点
func (this *MyLinkedList) Get(index int) int {
    if index >= this.size || index < 0 {
        return -1
    }
    
    cur := this.dummyHead.Next
    for index > 0 {
        cur = cur.Next
        index--
    }
    return cur.Val
}

// AddAtHead 在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
func (this *MyLinkedList) AddAtHead(val int) {
    newNode := &LinkedNode{Val: val}
    newNode.Next = this.dummyHead.Next
    this.dummyHead.Next = newNode
    this.size++
}

// AddAtTail 将值为 val 的节点追加到链表的最后一个元素。
func (this *MyLinkedList) AddAtTail(val int) {
    newNode := &LinkedNode{Val: val, Next: nil}
    cur := this.dummyHead
    for cur.Next != nil {
        cur = cur.Next
    }
    cur.Next = newNode
    this.size++
}

// AddAtIndex 在链表中的第 index 个节点之前添加值为 val 的节点。
// 如果 index 等于链表的长度，则该节点将附加到链表的末尾。
// 如果 index 大于链表长度，则不会插入节点。
// 如果index小于0，则在头部插入节点。
func (this *MyLinkedList) AddAtIndex(index int, val int) {
    if index > this.size {
        return
    }
    
    newNode := &LinkedNode{Val: val}
    cur := this.dummyHead
    for index > 0 {
        cur = cur.Next
        index--
    }
    newNode.Next = cur.Next
    cur.Next = newNode
    this.size++
}

// DeleteAtIndex 如果索引 index 有效，则删除链表中的第 index 个节点。
// 注意index是从0开始的
func (this *MyLinkedList) DeleteAtIndex(index int) {
    if index >= this.size || index < 0 {
        return
    }
    
    cur := this.dummyHead
    for index > 0 {
        cur = cur.Next
        index--
    }
    cur.Next = cur.Next.Next
    this.size--
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */