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
func (q *MyQueue) transfer() {
	if len(q.stOut) == 0 {
		for len(q.stIn) > 0 {
			q.stOut = append(q.stOut, q.stIn[len(q.stIn)-1])
			q.stIn = q.stIn[:len(q.stIn)-1]
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

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */