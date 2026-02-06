# 144. 二叉树的前序遍历

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
- **难度**：Easy
- **标签**：栈、树、深度优先搜索、二叉树

## 题目描述

给你二叉树的根节点 `root` ，返回它节点值的 **前序遍历** 结果。

前序遍历顺序：`根 -> 左 -> 右`。

## 示例

**示例 1：**
```
输入：root = [1,null,2,3]
输出：[1,2,3]
```

**示例 2：**
```
输入：root = []
输出：[]
```

**示例 3：**
```
输入：root = [1]
输出：[1]
```

## 解题思路

### 方法一：递归（DFS）

#### 思路与算法

首先我们需要了解什么是二叉树的前序遍历：按照访问根节点——左子树——右子树的方式遍历这棵树，而在访问左子树或者右子树的时候，我们按照同样的方式遍历，直到遍历完整棵树。因此整个遍历过程天然具有递归的性质，我们可以直接用递归函数来模拟这一过程。

定义 `preorder(root)` 表示当前遍历到 `root` 节点时的遍历结果。按照定义，我们只要：

1. 将 `root` 节点的值加入答案；
2. 递归调用 `preorder(root.left)` 遍历左子树；
3. 递归调用 `preorder(root.right)` 遍历右子树。

递归终止的条件为碰到空节点。

### 方法二：迭代（显式栈模拟递归）

#### 思路与算法

我们也可以用迭代的方式实现方法一的递归函数，两种方式是等价的。区别在于递归的时候隐式地维护了一个栈，而迭代时需要显式地将这个栈模拟出来，其余的实现与细节都相同。

具体做法是：

1. 用栈保存回溯路径；
2. 不断向左走的过程中：
   - 先访问当前节点（前序：先处理根）
   - 再将其入栈
3. 左侧走到底后弹栈，并转向右子树继续。

### 方法三：Morris 遍历（进阶，O(1) 额外空间）

#### 思路与算法

有一种巧妙的方法可以在线性时间内，只占用常数空间来实现前序遍历。这种方法由 J. H. Morris 在 1979 年的论文「Traversing Binary Trees Simply and Cheaply」中首次提出，因此被称为 Morris 遍历。

Morris 遍历的核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。其前序遍历规则可总结为：

1. 令当前节点为 `p1`（初始为 `root`）。
2. 如果 `p1.left` 为空：将 `p1` 加入答案，并令 `p1 = p1.right`。
3. 如果 `p1.left` 不为空：在 `p1` 的左子树中找到 `p1` 在中序遍历下的前驱节点 `p2`（即左子树最右节点）。
   - 若 `p2.right` 为空：将 `p2.right` 指向 `p1`（建立线索），将 `p1` 加入答案，并令 `p1 = p1.left`。
   - 若 `p2.right == p1`：说明线索已建立过，恢复 `p2.right = nullptr`，并令 `p1 = p1.right`。
4. 重复直到遍历结束。

## 代码实现

### C++

#### 递归
```cpp
class Solution {
public:
    void preorder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};
```

#### 迭代（栈）
```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;

        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                res.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return res;
    }
};
```

#### Morris 遍历
```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) return res;

        TreeNode *p1 = root, *p2 = nullptr;
        while (p1 != nullptr) {
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    res.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                }
            } else {
                res.emplace_back(p1->val);
            }
            p1 = p1->right;
        }
        return res;
    }
};
```

### Python

详见 [144_二叉树的前序遍历.py](./144_二叉树的前序遍历.py)

### Go

详见 [144_二叉树的前序遍历.go](./144_二叉树的前序遍历.go)

## 复杂度分析

设节点数为 `n`，树高为 `h`。

- **方法一（递归）**：
  - 时间复杂度：`O(n)`，每个节点恰好被遍历一次。
  - 空间复杂度：`O(h)`，为递归调用栈的开销；平均情况下为 `O(log n)`，最坏情况下树呈链状为 `O(n)`。
- **方法二（迭代）**：
  - 时间复杂度：`O(n)`，每个节点恰好被遍历一次。
  - 空间复杂度：`O(h)`，为显式栈的开销；平均情况下为 `O(log n)`，最坏情况下树呈链状为 `O(n)`。
- **方法三（Morris）**：
  - 时间复杂度：`O(n)`，没有左子树的节点只被访问一次，有左子树的节点会因为建立/恢复线索而被访问两次。
  - 空间复杂度：`O(1)`，只操作树上已有指针，额外空间为常数。

## 关键点

1. 前序遍历顺序固定为：**根 -> 左 -> 右**。
2. 迭代写法的关键是：
   - 入栈用于回溯
   - **先访问再入栈再向左**，与前序“先处理根”一致
3. Morris 遍历是进阶技巧：利用前驱节点建立/删除临时线索，达到 `O(1)` 额外空间。