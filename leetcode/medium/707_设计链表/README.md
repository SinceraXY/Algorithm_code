# 707. 设计链表

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/design-linked-list/description/
- **难度**：Medium
- **标签**：设计、链表

## 题目描述

设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：`val` 和 `next`。`val` 是当前节点的值，`next` 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 `prev` 以指示链表中的上一个节点。假设链表中的所有节点都是 0-indexed 的。

实现 `MyLinkedList` 类：
- `MyLinkedList()` 初始化 `MyLinkedList` 对象。
- `int get(int index)` 获取链表中下标为 `index` 的节点的值。如果下标无效，则返回 `-1`。
- `void addAtHead(int val)` 将一个值为 `val` 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
- `void addAtTail(int val)` 将一个值为 `val` 的节点追加到链表中作为链表的最后一个元素。
- `void addAtIndex(int index, int val)` 将一个值为 `val` 的节点插入到链表中下标为 `index` 的节点之前。如果 `index` 等于链表的长度，那么该节点会被追加到链表的末尾。如果 `index` 比长度更大，该节点将不会插入到链表中。
- `void deleteAtIndex(int index)` 如果下标有效，则删除链表中下标为 `index` 的节点。

**示例：**
```
输入
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
输出
[null, null, null, null, 2, null, 3]

解释
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
myLinkedList.get(1);              // 返回 2
myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
myLinkedList.get(1);              // 返回 3
```

**提示：**
- `0 <= index, val <= 1000`
- 请不要使用内置的 LinkedList 库。
- 调用 `get`、`addAtHead`、`addAtTail`、`addAtIndex` 和 `deleteAtIndex` 的次数不超过 `2000`。

## 解题思路

### 核心设计思想
使用**单链表 + 虚拟头节点**的设计：
1. **虚拟头节点**：设置一个不存储实际数据的虚拟头节点，简化边界处理
2. **大小记录**：维护链表的大小，优化索引验证和遍历
3. **统一操作**：所有插入和删除操作都通过统一的指针操作完成

### 关键技巧
- **虚拟头节点优势**：
  - 避免对头节点的特殊处理
  - 统一插入和删除的操作逻辑
  - 简化边界条件判断
- **索引遍历**：从虚拟头节点开始，遍历到目标位置
- **大小维护**：所有操作及时更新 `_size` 字段

## 代码实现

### C++ 实现
```cpp
class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList() {
        _dummyHead = new LinkedNode(0);   // 虚拟头结点
        _size = 0;
    }
    
    // 获取链表中第 index 个节点的值
    int get(int index) {
        if (index >= _size || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while (index--) {   // 注意：如果--index会陷入死循环
            cur = cur->next;
        }
        return cur->val;
    }
    
    // 在链表最前面插入一个节点
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    // 在链表最后面添加一个节点
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    // 在第index个节点之前插入一个新节点
    void addAtIndex(int index, int val) {
        if (index > _size) {
            return;
        }
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    // 删除第index个节点
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

private:
    int _size;
    LinkedNode* _dummyHead;
};
```

### Python 实现
```python
class MyLinkedList:
    # 定义链表节点类
    class LinkedNode:
        def __init__(self, val=0):
            self.val = val
            self.next = None

    def __init__(self):
        # 虚拟头结点
        self._dummy_head = self.LinkedNode(0)
        self._size = 0

    def get(self, index: int) -> int:
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
        if index >= self._size or index < 0:
            return
        
        cur = self._dummy_head
        while index > 0:
            cur = cur.next
            index -= 1
        cur.next = cur.next.next
        self._size -= 1
```

### Go 实现
```go
// 定义链表节点结构体
type LinkedNode struct {
    Val  int
    Next *LinkedNode
}

// MyLinkedList 设计链表
type MyLinkedList struct {
    dummyHead *LinkedNode // 虚拟头结点
    size      int
}

// Constructor 构造函数
func Constructor() MyLinkedList {
    return MyLinkedList{
        dummyHead: &LinkedNode{Val: 0, Next: nil},
        size:      0,
    }
}

// Get 获取链表中第 index 个节点的值
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

// AddAtHead 在链表的第一个元素之前添加一个节点
func (this *MyLinkedList) AddAtHead(val int) {
    newNode := &LinkedNode{Val: val}
    newNode.Next = this.dummyHead.Next
    this.dummyHead.Next = newNode
    this.size++
}

// AddAtTail 将节点追加到链表的最后一个元素
func (this *MyLinkedList) AddAtTail(val int) {
    newNode := &LinkedNode{Val: val, Next: nil}
    cur := this.dummyHead
    for cur.Next != nil {
        cur = cur.Next
    }
    cur.Next = newNode
    this.size++
}

// AddAtIndex 在链表中的第 index 个节点之前添加节点
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

// DeleteAtIndex 删除链表中的第 index 个节点
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
```

## 复杂度分析

### 时间复杂度
- **get(index)**：`O(index)` - 需要遍历到目标位置
- **addAtHead(val)**：`O(1)` - 直接在头部插入
- **addAtTail(val)**：`O(n)` - 需要遍历到尾部
- **addAtIndex(index, val)**：`O(index)` - 需要遍历到目标位置
- **deleteAtIndex(index)**：`O(index)` - 需要遍历到目标位置

### 空间复杂度
- **整体空间复杂度**：`O(n)` - n为链表中节点的数量
- **单次操作空间**：`O(1)` - 只使用常数级额外空间

## 关键要点

### 设计思路
1. **虚拟头节点**：简化边界处理，统一操作逻辑
2. **大小维护**：实时更新链表大小，优化边界检查
3. **指针操作**：掌握链表的基本指针操作

### 实现细节
- **边界检查**：所有涉及索引的操作都要检查边界
- **内存管理**：C++中需要手动释放删除的节点内存
- **循环条件**：注意C++中使用`index--`而不是`--index`

### 优化点
- **addAtTail优化**：可以维护尾指针，将时间复杂度从O(n)优化到O(1)
- **双向链表**：可以实现双向链表版本，支持反向遍历

## 相关题目

- [203. 移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/) - 链表删除操作
- [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/) - 链表反转
- [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/) - 链表合并

