class MyQueue {
private:
    stack<int> stIn;   //输入栈
    stack<int> stOut;  //输出栈

    //辅助函数：将 stIn 元素转移到 stOut
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



/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */