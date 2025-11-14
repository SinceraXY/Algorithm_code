# 232. 用栈实现队列

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/implement-queue-using-stacks/description/
- **难度**：Easy
- **标签**：栈、设计、队列

## 题目描述

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（`push`、`pop`、`peek`、`empty`）：

实现 `MyQueue` 类：
- `void push(int x)` 将元素 x 推到队列的末尾
- `int pop()` 从队列的开头移除并返回元素
- `int peek()` 返回队列开头的元素
- `boolean empty()` 如果队列为空，返回 `true`；否则，返回 `false`

**说明：**
- 你只能使用标准的栈操作 —— 也就是只有 `push to top`, `peek/pop from top`, `size`, 和 `is empty` 操作是合法的。
- 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

## 解题思路

### 双栈实现队列

使用两个栈来实现队列：
- **输入栈 (stIn)**：负责接收新元素
- **输出栈 (stOut)**：负责输出元素

**核心思想**：
1. `push` 操作：直接将元素压入输入栈
2. `pop`/`peek` 操作：
   - 如果输出栈不为空，直接从输出栈操作
   - 如果输出栈为空，将输入栈的所有元素转移到输出栈，然后操作

**转移策略**：
- 只有当输出栈为空时，才将输入栈的元素全部转移到输出栈
- 这样确保了先进先出的顺序

### 时间复杂度
- `push`：O(1)
- `pop`：摊还时间复杂度 O(1)，最坏情况 O(n)
- `peek`：摊还时间复杂度 O(1)，最坏情况 O(n)  
- `empty`：O(1)

### 空间复杂度
O(n) - 其中 n 是操作总数。对于有 n 次 push 操作的情况，队列中会有 n 个元素，故空间复杂度为 O(n)。

## 代码实现

### C++
```cpp
class MyQueue {
private:
    stack<int> stIn;   // 输入栈
    stack<int> stOut;  // 输出栈
    
    // 辅助函数：将 stIn 元素转移到 stOut
    void transfer() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
    }

public:
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        transfer();
        int res = stOut.top();
        stOut.pop();
        return res;
    }
    
    int peek() {
        transfer();
        return stOut.top();
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};
```

### Python
```python
class MyQueue:
    def __init__(self):
        self.st_in = []   # 输入栈
        self.st_out = []  # 输出栈

    def _transfer(self):
        """辅助函数：将 st_in 元素转移到 st_out"""
        if not self.st_out:
            while self.st_in:
                self.st_out.append(self.st_in.pop())

    def push(self, x: int) -> None:
        self.st_in.append(x)

    def pop(self) -> int:
        self._transfer()
        return self.st_out.pop()

    def peek(self) -> int:
        self._transfer()
        return self.st_out[-1]

    def empty(self) -> bool:
        return not self.st_in and not self.st_out
```

### Go
```go
type MyQueue struct {
    stIn  []int // 输入栈
    stOut []int // 输出栈
}

func Constructor() MyQueue {
    return MyQueue{
        stIn:  []int{},
        stOut: []int{},
    }
}

// 辅助函数：将 stIn 元素转移到 stOut
func (this *MyQueue) transfer() {
    if len(this.stOut) == 0 {
        for len(this.stIn) > 0 {
            this.stOut = append(this.stOut, this.stIn[len(this.stIn)-1])
            this.stIn = this.stIn[:len(this.stIn)-1]
        }
    }
}

func (this *MyQueue) Push(x int) {
    this.stIn = append(this.stIn, x)
}

func (this *MyQueue) Pop() int {
    this.transfer()
    res := this.stOut[len(this.stOut)-1]
    this.stOut = this.stOut[:len(this.stOut)-1]
    return res
}

func (this *MyQueue) Peek() int {
    this.transfer()
    return this.stOut[len(this.stOut)-1]
}

func (this *MyQueue) Empty() bool {
    return len(this.stIn) == 0 && len(this.stOut) == 0
}
```

## 示例

```
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek();  // return 1
myQueue.pop();   // return 1, queue is [2]
myQueue.empty(); // return false
```

## 关键点

1. **双栈策略**：输入栈负责入队，输出栈负责出队
2. **懒惰转移**：只有输出栈为空时才转移元素，提高效率
3. **FIFO保证**：通过栈的后进先出特性，两次反转实现先进先出