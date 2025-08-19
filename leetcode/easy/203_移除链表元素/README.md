# 203. 移除链表元素

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/remove-linked-list-elements/description/
- **难度**：Easy
- **标签**：递归、链表

## 题目描述

给你一个链表的头节点 `head` 和一个整数 `val`，请你删除链表中所有满足 `Node.val == val` 的节点，并返回新的头节点。

**示例 1：**
```
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
```

**示例 2：**
```
输入：head = [], val = 1
输出：[]
```

**示例 3：**
```
输入：head = [7,7,7,7], val = 7
输出：[]
```

**提示：**
- 列表中的节点数目在范围 `[0, 10⁴]` 内
- `1 <= Node.val <= 50`
- `0 <= val <= 50`

## 解题思路

### 方法一：直接在原链表上操作

**核心思想**：分别处理头节点和非头节点的删除情况

**步骤**：
1. **处理头节点**：用 `while` 循环删除所有满足条件的头节点
2. **处理其他节点**：遍历链表，删除满足条件的节点

**注意点**：
- 头节点的删除需要特殊处理，因为没有前驱节点
- 使用 `while` 而非 `if` 处理连续多个满足条件的头节点

### 方法二：虚拟头节点（推荐）

**核心思想**：设置虚拟头节点，统一处理所有节点的删除操作

**优势**：
- 避免了头节点的特殊处理
- 代码逻辑更简洁统一
- 更易理解和维护

**步骤**：
1. 创建虚拟头节点，指向原头节点
2. 用指针遍历，统一处理所有节点的删除
3. 返回虚拟头节点的下一个节点

## 代码实现

### C++ 实现

#### 方法一：直接操作原链表
```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 处理头节点，注意这里是while不是if
        while(head != NULL && head->val == val) {    
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        
        // 处理其他节点
        ListNode* cur = head;
        while(cur != NULL && cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
```

#### 方法二：虚拟头节点
```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);    // 设置虚拟头节点
        dummyHead->next = head;                   // 将虚拟头节点指向head
        ListNode* cur = dummyHead;
        
        while(cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};
```

### Python 实现
```python
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy_head = ListNode(0)  # 设置虚拟头节点
        dummy_head.next = head    # 将虚拟头节点指向head，方便后面做删除操作
        cur = dummy_head
        
        while cur.next is not None:
            if cur.next.val == val:
                cur.next = cur.next.next  # 删除cur.next节点
            else:
                cur = cur.next
        
        return dummy_head.next
```

### Go 实现
```go
func removeElements(head *ListNode, val int) *ListNode {
    dummyHead := &ListNode{Next: head}  // 设置虚拟头节点
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
```

## 复杂度分析

- **时间复杂度**：`O(n)`
  - 需要遍历整个链表一次，其中 n 是链表的长度
  - 每个节点最多被访问一次

- **空间复杂度**：`O(1)`
  - 只使用了常数级别的额外空间
  - 虚拟头节点只占用一个节点的空间

## 关键要点

### 方法一：直接操作
1. **头节点处理**：使用 `while` 循环而非 `if`，处理连续多个需要删除的头节点
2. **内存管理**：C++中需要手动释放删除节点的内存
3. **边界检查**：确保指针不为空再访问其成员

### 方法二：虚拟头节点
1. **统一处理**：虚拟头节点使得头节点和其他节点的删除逻辑完全一致
2. **简化代码**：避免了复杂的边界条件判断
3. **推荐使用**：代码更简洁，逻辑更清晰

## 总结

虚拟头节点是链表操作中的经典技巧，特别适用于需要删除头节点的场景。它通过引入一个额外的节点，将特殊情况转化为一般情况，大大简化了代码逻辑。

## 相关题目

- [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/) - 链表合并
- [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/) - 链表反转
- [83. 删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/) - 链表删除
