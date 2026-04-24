# 199. 二叉树的右视图

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/binary-tree-right-side-view/description/
- **难度**：Medium
- **标签**：树、深度优先搜索、广度优先搜索、二叉树

## 题目描述

给定一个二叉树的根节点 `root`，想象你站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

## 示例

**示例 1：**
```
输入：root = [1,2,3,null,5,null,4]
输出：[1,3,4]
```

**示例 2：**
```
输入：root = [1,null,3]
输出：[1,3]
```

**示例 3：**
```
输入：root = []
输出：[]
```

## 解题思路

### 方法一：迭代（广度优先搜索 BFS）

#### 思路与算法

右视图等价于：**每一层最右侧（最后被遍历到）的那个节点**。

用 BFS 层序遍历即可：

1. 使用队列按层遍历二叉树。
2. 每次循环前记录当前层节点数 `size`。
3. 依次弹出当前层的 `size` 个节点：
   - 当 `i == size - 1` 时，说明该节点是本层最后一个节点（也就是最右侧能看到的节点），将其值加入答案。
   - 将其左右孩子按顺序入队。

## 代码实现

### C++

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<int> result;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == size - 1) result.push_back(node->val);    // 将每一层的最后元素放入 result 中
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};
```

### Python

详见 [199_二叉树的右视图.py](./199_二叉树的右视图.py)

### Go

详见 [199_二叉树的右视图.go](./199_二叉树的右视图.go)

## 复杂度分析

设节点数为 `n`。

- **时间复杂度**：每个点进队出队各一次，故渐进时间复杂度为 $O(n)$。
- **空间复杂度**：队列中元素的个数不超过 $n$ 个，故渐进空间复杂度为 $O(n)$。

## 关键点

1. 右视图 = 每层的最后一个节点。
2. BFS 分层遍历时一定要先记录固定的 `size`，避免队列长度在遍历过程中变化导致层边界出错。