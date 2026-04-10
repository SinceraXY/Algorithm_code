# 145. 二叉树的后序遍历

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
- **难度**：Easy
- **标签**：栈、树、深度优先搜索、二叉树

## 题目描述

给你二叉树的根节点 `root` ，返回它节点值的 **后序遍历** 结果。

后序遍历顺序：`左 -> 右 -> 根`。

## 示例

**示例 1：**
```
输入：root = [1,null,2,3]
输出：[3,2,1]
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

后序遍历的顺序是“左子树 -> 右子树 -> 根节点”。当我们遍历到任意一个节点 `root` 时，
它的左子树和右子树本身也都是二叉树，因此可以用同样的规则递归遍历：

1. 递归遍历 `root.left`
2. 递归遍历 `root.right`
3. 最后把 `root.val` 加入结果

递归终止条件：当前节点为空。

### 方法二：迭代（显式栈模拟递归）

#### 思路与算法

后序遍历在迭代实现时的难点在于：

- 你从栈里弹出一个节点 `cur` 时，并不能立刻访问它（因为要先保证右子树已经处理完）。

**1. 经典迭代（双指针法）：**

1. 用栈模拟递归的“向左走到底”；
2. 弹出栈顶节点 `cur` 后：
   - 如果 `cur.right` 为空，或者 `cur.right == prev`（上一个访问过的节点），说明右子树已处理完，可以访问 `cur`；
   - 否则把 `cur` 再压回栈中，转而处理右子树。

**2. 通用迭代（前序反转法）：**

前序遍历顺序是“中左右”，将其代码逻辑稍作修改：
1. 入栈顺序改为：先左后右。
2. 出栈顺序则变为：中右左。
3. 最后将结果数组整体反转，得到：左右中（即后序遍历）。

**3. 统一迭代法（标记法）：**

使用 `NULL` 指针作为标记位，实现访问与处理逻辑的分离。
- 入栈顺序为：**中 -> 右 -> 左**（栈先进后出，出栈即为左右中）。
- 每次将中节点入栈后，紧跟一个 `NULL` 标记。
- 弹出 `NULL` 时，处理其后的节点。

### 方法三：Morris 遍历（进阶，O(1) 额外空间）

#### 思路与算法

Morris 遍历的核心思想是“利用空闲指针建立临时线索”，从而在遍历时无需显式栈。

针对后序遍历（左 -> 右 -> 根），一种常见技巧是：

- 当我们从某个节点的左子树“回到”该节点时（即恢复线索的时刻），就可以把左子树从该节点出发沿右指针走到尽头的路径收集起来，
  再进行一次局部反转，使得这段路径的输出顺序符合后序的要求。

本仓库的实现中使用了 `addPath`：

- 沿着 `node` 的右指针一路把值加入 `res`
- 再把这段新增区间就地 `reverse`，从而得到正确的输出顺序

最后再对整棵树执行一次 `addPath(root)`，补上最后一段路径。

## 代码实现

### C++

#### 递归

```cpp
class Solution {
public:
    void postorder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};
```

#### 迭代（栈）

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || root->right == prev) {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};
```

#### 迭代（前序反转方式）

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序
            if (node->right) st.push(node->right);
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
};
```

#### 迭代（统一标记法）

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);                          // 中
                st.push(NULL);

                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左

            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};
```

#### Morris 遍历

```cpp
class Solution {
public:
    void addPath(vector<int> &vec, TreeNode *node) {
        int count = 0;
        while (node != nullptr) {
            ++count;
            vec.emplace_back(node->val);
            node = node->right;
        }
        reverse(vec.end() - count, vec.end());
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        TreeNode *p1 = root, *p2 = nullptr;

        while (p1 != nullptr) {
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                    addPath(res, p1->left);
                }
            }
            p1 = p1->right;
        }
        addPath(res, root);
        return res;
    }
};
```

### Python

详见 [145_二叉树的后序遍历.py](./145_二叉树的后序遍历.py)

### Go

详见 [145_二叉树的后序遍历.go](./145_二叉树的后序遍历.go)

## 复杂度分析

设节点数为 `n`，树高为 `h`。

- **方法一（递归）**：
  - 时间复杂度：`O(n)`，每个节点恰好被遍历一次。
  - 空间复杂度：`O(h)`，为递归调用栈的开销；平均情况下为 `O(log n)`，最坏情况下树呈链状为 `O(n)`。
- **方法二（迭代）**：
  - 时间复杂度：`O(n)`，每个节点恰好被遍历一次。
  - 空间复杂度：`O(h)`，为显式栈的开销；平均情况下为 `O(log n)`，最坏情况下树呈链状为 `O(n)`。
- **方法三（Morris）**：
  - 时间复杂度：`O(n)`，部分节点会因为建立/恢复线索以及路径反转而被处理多次，但总次数仍为线性级别。
  - 空间复杂度：`O(1)`，只操作树上已有指针，额外空间为常数。

## 关键点

1. 后序遍历顺序固定为：**左 -> 右 -> 根**。
2. 迭代写法的关键是使用 `prev` 判断“右子树是否已经处理完”，避免过早访问根。
3. Morris 后序遍历通常需要配合“收集一段右链并反转”的技巧（本实现用 `addPath + reverse` 完成）。