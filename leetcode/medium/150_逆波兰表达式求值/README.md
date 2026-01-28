# 150. 逆波兰表达式求值

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/
- **难度**：Medium
- **标签**：栈、数组、数学

## 题目描述

给你一个字符串数组 `tokens` ，表示一个根据 **逆波兰表示法**（Reverse Polish Notation, RPN）表示的算术表达式。

请你计算该表达式的值并返回。

**注意：**
1. 有效的算符为：`+`、`-`、`*`、`/`。
2. 每个操作数可以是一个整数，也可以是一个表达式。
3. 两个整数之间的除法只保留整数部分（向 0 取整）。

## 示例

**示例 1：**
```
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：((2 + 1) * 3) = 9
```

**示例 2：**
```
输入：tokens = ["4","13","5","/","+"]
输出：6
解释：(4 + (13 / 5)) = 6
```

**示例 3：**
```
输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
```

## 解题思路

### 方法：栈

**核心思路：**
- 逆波兰表达式从左到右扫描时：
  - 遇到数字：入栈。
  - 遇到运算符：弹出两个数进行计算，并将结果入栈。
- 最终栈顶元素即为表达式结果。

**关键细节：**
- 由于栈是后进先出，遇到运算符时弹出的顺序是：
  - 第一次弹出的是右操作数 `num1`
  - 第二次弹出的是左操作数 `num2`
- 对于 `-` 和 `/` 这类非交换运算，必须按 `num2 op num1` 的顺序计算。

## 代码实现

### C++

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(tokens[i]=="+") st.push(num2+num1);
                if(tokens[i]=="-") st.push(num2-num1);
                if(tokens[i]=="*") st.push(num2*num1);
                if(tokens[i]=="/") st.push(num2/num1);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        int result = st.top();
        st.pop(); //把栈里最后一个元素弹出（其实不弹出也没事）
        return result;
    }
};
```

## 复杂度分析

- **时间复杂度**：O(n)，其中 n 是数组 tokens 的长度。需要遍历数组 tokens 一次，计算逆波兰表达式的值。
- **空间复杂度**：O(n)，其中 n 是数组 tokens 的长度。使用栈存储计算过程中的数，栈内元素个数不会超过逆波兰表达式的长度。

## 关键点

1. 遇到运算符时要先弹出右操作数，再弹出左操作数。
2. 除法按题意向 0 取整，C++ 整数除法符合该规则。
3. 最终答案即栈顶元素。