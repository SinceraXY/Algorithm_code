# 71. 简化路径

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/simplify-path/description/
- **难度**：Medium
- **标签**：栈、字符串

## 题目描述

给你一个字符串 `path` ，表示指向某个文件或目录的 Unix 风格绝对路径。

请你将其转化为更加简洁的规范路径。

**规则：**
1. `.` 表示当前目录，忽略。
2. `..` 表示上一级目录（如果已经在根目录 `/`，则继续保持在根目录）。
3. 多个连续的 `/` 视为一个 `/`。
4. 规范路径必须以 `/` 开头，且不能以 `/` 结尾（根目录 `/` 除外）。

返回规范化后的路径。

## 示例

**示例 1：**
```
输入：path = "/home/"
输出："/home"
```

**示例 2：**
```
输入：path = "/../"
输出："/"
```

**示例 3：**
```
输入：path = "/home//foo/"
输出："/home/foo"
```

## 解题思路

### 方法：栈（模拟目录层级）

**核心思路：**
- 以 `/` 为分隔符，把路径切分成若干段（目录名）。
- 用一个“栈”（可用数组 / `vector` / `list`）维护当前已经确认的目录层级：
  - 遇到空串 `""` 或 `.`：跳过。
  - 遇到 `..`：如果栈非空则弹出栈顶；如果栈为空说明已经在根目录，忽略。
  - 其他普通目录名：入栈。
- 最后把栈中目录用 `/` 拼接回去：
  - 栈空则答案为 `/`。
  - 否则答案为 `"/" + join(stack, "/")`。

**为什么要用栈：**
- `..` 的语义是“回到上一级目录”，天然符合 LIFO（后进先出）的回退行为。

## 代码实现

### C++
```cpp
class Solution {
 public:
     string simplifyPath(string path) {
         auto split = [](const string& s, char delim) -> vector<string> {
             vector<string> ans;
             string cur;
             for(char ch: s) {
                 if(ch==delim){
                     ans.push_back(move(cur));
                     cur.clear();
                 }
                 else {
                     cur += ch;
                 }
             }
             ans.push_back(move(cur));
             return ans;
         };

         vector<string> names = split(path, '/');
         vector<string> stack;
         for(string& name: names) {
             if(name=="..") {
                 if(!stack.empty()) {
                     stack.pop_back();
                 }
             }
             else if(!name.empty()&&name!=".") {
                 stack.push_back(move(name));
             }
         }
         string ans;
         if(stack.empty()) {
             ans="/";
         }
         else {
             for(string& name:stack) {
                 ans += "/" + move(name);
             }
         }
         return ans;
     }
 };
```

本题提供了三种语言的实现（思路一致）：

- [C++ 实现](./71_简化路径.cpp)
- [Python 实现](./71_简化路径.py)
- [Go 实现](./71_简化路径.go)

## 复杂度分析

设 `n` 为字符串 `path` 的长度。

- **时间复杂度**：O(n)。切分 + 扫描每个字符/片段一次，最终拼接同阶。
- **空间复杂度**：O(n)。栈在最坏情况下存下所有目录名（不考虑返回字符串本身也同阶）。

## 关键点

1. 分割后会出现空串（例如前导 `/`、尾部 `/`、以及 `//`），需要跳过。
2. `..` 只有在栈非空时才弹栈，否则代表已经在根目录。
3. 最终结果：
   - 栈为空返回 `/`。
   - 栈非空用 `/` 连接，并确保不以 `/` 结尾。