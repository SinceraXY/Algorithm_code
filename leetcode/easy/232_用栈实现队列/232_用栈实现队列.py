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



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()