# 206. 反转链表

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/reverse-linked-list/description/
- **难度**：Easy
- **标签**：递归、链表

## 题目描述

给你单链表的头节点 `head`，请你反转链表，并返回反转后的链表。

**示例 1：**
```
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
```

**示例 2：**
```
输入：head = [1,2]
输出：[2,1]
```

**示例 3：**
```
输入：head = []
输出：[]
```

**提示：**
- 链表中节点的数目范围是 `[0, 5000]`
- `-5000 <= Node.val <= 5000`

## 解法思路

### 方法一：双指针法（迭代）

**核心思路：** 使用三个指针 `pre`、`cur`、`temp` 来实现链表反转。
- `pre`：指向当前节点的前一个节点
- `cur`：指向当前正在处理的节点
- `temp`：临时保存当前节点的下一个节点

**算法步骤：**
1. 初始化：`pre = NULL`，`cur = head`
2. 遍历链表，对每个节点执行：
   - 保存下一节点：`temp = cur.next`
   - 反转当前链接：`cur.next = pre`
   - 移动指针：`pre = cur`，`cur = temp`
3. 返回 `pre`（新的头节点）

### 方法二：递归法

递归的思路是将问题分解：先递归处理子链表，再处理当前节点。

## 代码实现

### C++ 实现

#### 双指针法
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;   // 保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
```

#### 递归法
```cpp
class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if(cur == NULL) {
            return pre;
        }
        ListNode* temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }
};
```

### Python 实现

```python
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = None    # 保存cur的下一个节点
        cur = head
        pre = None
        while cur:
            temp = cur.next
            cur.next = pre
            pre = cur
            cur = temp
        return pre
```

### Go 实现

```go
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
```

## 复杂度分析

- **时间复杂度**：O(n)，其中 n 是链表的长度。需要遍历链表一次。
- **空间复杂度**：
  - 双指针法：O(1)，只使用了常数级别的额外空间
  - 递归法：O(n)，递归调用栈的深度为 n

## 关键点总结

1. **双指针法**是最优解，时间和空间复杂度都很理想
2. **临时指针**的作用是防止断链，确保能够继续遍历
3. **指针移动的顺序**很重要：先保存下一节点，再反转，最后移动
4. **边界情况**：空链表和单节点链表都能正确处理