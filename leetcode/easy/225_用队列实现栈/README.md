# 225. 用队列实现栈

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/implement-stack-using-queues/description/
- **难度**：Easy
- **标签**：栈、设计、队列

## 题目描述

请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（`push`、`top`、`pop` 和 `empty`）。

实现 `MyStack` 类：
- `void push(int x)` 将元素 x 压入栈顶。
- `int pop()` 移除并返回栈顶元素。
- `int top()` 返回栈顶元素。
- `boolean empty()` 如果栈是空的，返回 true；否则，返回 false。

**注意：**
- 你只能使用队列的基本操作 —— 也就是 `push to back`、`peek/pop from front`、`size` 和 `is empty` 这些操作。
- 你所使用的语言也许不支持队列。你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

## 解题思路

使用两个队列来模拟栈的行为，核心思想是保持一个队列（queue1）始终按照栈的顺序存储元素。

### 算法步骤：

1. **Push操作**：
   - 将新元素放入 queue2
   - 将 queue1 中的所有元素依次移到 queue2
   - 交换 queue1 和 queue2 的引用

2. **Pop操作**：
   - 直接从 queue1 的队头取出元素

3. **Top操作**：
   - 返回 queue1 的队头元素（不移除）

4. **Empty操作**：
   - 检查 queue1 是否为空

### 复杂度分析：
- **时间复杂度**：
  - Push: O(n)，其中 n 是栈中元素的个数
  - Pop, Top, Empty: O(1)
- **空间复杂度**：O(n)，用于存储 n 个元素

## 代码实现

### C++ 实现
```cpp
class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;

    MyStack() {}
    
    void push(int x) {
        queue2.push(x);
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        swap(queue1, queue2);
    }
    
    int pop() {
        int r = queue1.front();
        queue1.pop();
        return r;
    }
    
    int top() {
        return queue1.front();
    }
    
    bool empty() {
        return queue1.empty();
    }
};
```

### Python 实现
```python
from collections import deque

class MyStack:
    def __init__(self):
        self.queue1 = deque()
        self.queue2 = deque()

    def push(self, x: int) -> None:
        self.queue2.append(x)
        while self.queue1:
            self.queue2.append(self.queue1.popleft())
        self.queue1, self.queue2 = self.queue2, self.queue1

    def pop(self) -> int:
        return self.queue1.popleft()

    def top(self) -> int:
        return self.queue1[0]

    def empty(self) -> bool:
        return len(self.queue1) == 0
```

### Go 实现
```go
type MyStack struct {
    queue1 []int
    queue2 []int
}

func Constructor() MyStack {
    return MyStack{
        queue1: []int{},
        queue2: []int{},
    }
}

func (this *MyStack) Push(x int) {
    this.queue2 = append(this.queue2, x)
    for len(this.queue1) > 0 {
        this.queue2 = append(this.queue2, this.queue1[0])
        this.queue1 = this.queue1[1:]
    }
    this.queue1, this.queue2 = this.queue2, this.queue1
}

func (this *MyStack) Pop() int {
    r := this.queue1[0]
    this.queue1 = this.queue1[1:]
    return r
}

func (this *MyStack) Top() int {
    return this.queue1[0]
}

func (this *MyStack) Empty() bool {
    return len(this.queue1) == 0
}
```

## 关键点

1. **双队列转换**：通过两个队列的转换来维持栈的LIFO特性
2. **Push操作的关键**：新元素先入queue2，然后将queue1的元素依次转移，最后交换引用
3. **空间换时间**：虽然Push操作是O(n)，但其他操作都是O(1)
4. **队列模拟**：不同语言使用不同的数据结构来模拟队列（deque、slice等）