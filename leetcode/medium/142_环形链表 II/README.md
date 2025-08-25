# 142. 环形链表 II

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/linked-list-cycle-ii/description/
- **难度**：Medium
- **标签**：哈希表、链表、双指针

## 题目描述

给定一个链表的头节点 `head`，返回链表开始入环的第一个节点。如果链表无环，则返回 `null`。

如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。为了表示给定链表中的环，评测系统内部使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 `pos` 是 `-1`，则在该链表中没有环。注意：`pos` 不作为参数进行传递，仅仅是为了标识链表的实际情况。

**不允许修改** 链表。

**示例 1：**
```
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
```

**示例 2：**
```
输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
```

**示例 3：**
```
输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
```

**提示：**
- 链表中节点的数目范围在范围 `[0, 10^4]` 内
- `-10^5 <= Node.val <= 10^5`
- `pos` 的值为 `-1` 或者链表中的一个有效索引

## 解法思路

### 方法一：哈希表法

**核心思路：** 遍历链表，使用哈希表记录访问过的节点。当遇到已访问过的节点时，该节点就是环的入口。

**算法步骤：**
1. 创建哈希表存储访问过的节点
2. 遍历链表，对每个节点：
   - 检查节点是否已在哈希表中
   - 如果在，返回该节点（环入口）
   - 如果不在，将节点加入哈希表
3. 遍历结束未发现环，返回 null

### 方法二：快慢指针法（Floyd判圈算法）

**核心思路：** 使用数学原理，通过快慢指针找到环的入口。

**算法步骤：**
1. **第一阶段**：检测是否有环
   - 快指针每次走2步，慢指针每次走1步
   - 如果有环，快慢指针必定相遇
2. **第二阶段**：找到环入口
   - 一个指针从头节点开始，另一个从相遇点开始
   - 两指针都每次走1步，再次相遇的点就是环入口

**数学原理：**
设环入口距离头节点为 `a`，相遇点距离环入口为 `b`，环的剩余长度为 `c`。
- 慢指针走过距离：`a + b`
- 快指针走过距离：`a + b + c + b = a + 2b + c`
- 由于快指针速度是慢指针的2倍：`a + 2b + c = 2(a + b)`
- 化简得：`a = c`

因此，从头节点和相遇点同时出发，每次走1步，相遇点就是环入口。

## 代码实现

### C++ 实现

#### 哈希表法
```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while (head != nullptr) {
            if (visited.count(head)) {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
```

#### 快慢指针法
```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return NULL;
    }
};
```

### Python 实现

#### 哈希表法
```python
class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        visited = set()
        while head is not None:
            if head in visited:
                return head
            visited.add(head)
            head = head.next
        return None
```

#### 快慢指针法
```python
class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = head
        slow = head
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                index1 = fast
                index2 = head
                while index1 != index2:
                    index1 = index1.next
                    index2 = index2.next
                return index2
        return None
```

### Go 实现

#### 哈希表法
```go
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
```

#### 快慢指针法
```go
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
```

## 复杂度分析

### 哈希表法
- **时间复杂度**：O(n)，其中 n 是链表中的节点数。最坏情况下需要访问所有节点。
- **空间复杂度**：O(n)，需要哈希表存储访问过的节点。

### 快慢指针法
- **时间复杂度**：O(n)，其中 n 是链表中的节点数。
  - 第一阶段最多遍历整个链表
  - 第二阶段最多遍历环的长度
- **空间复杂度**：O(1)，只使用常数级别的额外空间。

## 关键点总结

1. **哈希表法**简单直观，但需要额外空间
2. **快慢指针法**是最优解，空间复杂度为O(1)
3. **数学原理**是快慢指针法的核心，理解 `a = c` 的推导很重要
4. **边界情况**：空链表、无环链表、单节点环都能正确处理
5. **指针操作**要注意空指针检查，避免访问 `nullptr->next`