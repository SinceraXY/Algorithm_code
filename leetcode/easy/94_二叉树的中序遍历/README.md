# 94. 二叉树的中序遍历

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
- **难度**：Easy
- **标签**：栈、树、深度优先搜索、二叉树

## 题目描述

给你二叉树的根节点 `root` ，返回它节点值的 **中序遍历** 结果。

中序遍历顺序：`左 -> 根 -> 右`。

## 示例

**示例 1：**
```
输入：root = [1,null,2,3]
输出：[1,3,2]
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

中序遍历的顺序是“左子树 -> 根节点 -> 右子树”。当遍历到任意节点 `root` 时：

1. 递归遍历 `root.left`
2. 将 `root.val` 加入结果
3. 递归遍历 `root.right`

递归终止条件：当前节点为空。

### 方法二：迭代（显式栈模拟递归）

#### 思路与算法

递归遍历时，系统会隐式维护一条从根到当前节点的路径栈。迭代写法本质上是把这个“隐式栈”改为“显式栈”。

**1. 经典迭代（指针访问 + 栈处理）：**

这种方式利用指针 `cur` 模拟访问节点的路径，利用栈 `st` 记录待处理的节点。

1. **访问阶段**：指针 `cur` 不断向左子树深入，将沿途经过的节点压入栈中，直到 `cur` 为空。
2. **处理阶段**：从栈中弹出节点。由于栈是先进后出，最先弹出的节点必定是当前路径上“最左下”的节点。
3. **转向阶段**：访问该弹出节点的值后，将指针 `cur` 指向该节点的右孩子，重复上述过程。

这种方式的特点是：**指针负责遍历（找节点），栈负责处理（存节点）**。

**2. 统一迭代法（标记法）：**

由于中序遍历的访问顺序（根、左、右）和处理顺序（左、根、右）不一致，传统的迭代代码通常与前序和后序不统一。

为了实现统一，可以使用“标记法”：
- 将访问的节点放入栈中。
- 如果该节点是待处理的（即需要放入结果集的），在其后方压入一个 `NULL` 指针作为标记。
- 当从栈中弹出 `NULL` 时，表示下一个弹出的节点即为待处理节点。

中序遍历的入栈顺序应为：**右 -> 中 -> 左**（栈是先进后出，所以出栈顺序为左中右）。

### 方法三：Morris 遍历（进阶，O(1) 额外空间）

#### 思路与算法

Morris 中序遍历利用树中的空闲指针建立临时线索，从而避免显式栈。

对当前节点 `root`：

1. 如果 `root.left` 为空：直接访问 `root`，然后 `root = root.right`。
2. 如果 `root.left` 不为空：找到 `root` 的中序前驱 `predecessor`（左子树最右节点）。
   - 若 `predecessor.right` 为空：令 `predecessor.right = root` 建立线索，并令 `root = root.left` 继续遍历左子树。
   - 若 `predecessor.right == root`：说明左子树已遍历完，先访问 `root`，再恢复 `predecessor.right = nullptr`，并令 `root = root.right`。

## 代码实现

### C++

#### 递归

```cpp
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
```

#### 迭代（栈）

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
```

#### 迭代（经典方式）

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 讲访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                result.push_back(cur->val);     // 中
                cur = cur->right;               // 右
            }
        }
        return result;
    }
};
```

#### 迭代（统一标记法）

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();  //将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right) st.push(node->right);  //添加右节点（空节点不入栈）

                st.push(node);                          //添加中节点
                st.push(NULL); //中节点访问过，但是还没有处理，加入空节点做为标记。

                if (node->left) st.push(node->left);    //添加左节点（空节点不入栈）
            } else {      //只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();           //将空节点弹出
                node = st.top();    //重新取出栈中元素
                st.pop();
                result.push_back(node->val);       //加入到结果集
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
```

### Python

详见 [94_二叉树的中序遍历.py](./94_二叉树的中序遍历.py)

### Go

详见 [94_二叉树的中序遍历.go](./94_二叉树的中序遍历.go)

## 复杂度分析

设节点数为 `n`，树高为 `h`。

- **方法一（递归）**：
  - 时间复杂度：`O(n)`，每个节点恰好被遍历一次。
  - 空间复杂度：`O(h)`，为递归调用栈的开销；平均情况下为 `O(log n)`，最坏情况下树呈链状为 `O(n)`。
- **方法二（迭代）**：
  - 时间复杂度：`O(n)`，每个节点恰好被遍历一次。
  - 空间复杂度：`O(h)`，为显式栈的开销；平均情况下为 `O(log n)`，最坏情况下树呈链状为 `O(n)`。
- **方法三（Morris）**：
  - 时间复杂度：`O(n)`，建立/恢复线索会让部分节点被处理多次，但总次数仍为线性级别。
  - 空间复杂度：`O(1)`，只操作树上已有指针，额外空间为常数。

## 关键点

1. 中序遍历顺序固定为：**左 -> 根 -> 右**。
2. 迭代写法的关键是“先一路入栈走到最左，再出栈访问，再转向右子树”。
3. Morris 遍历会临时修改指针（建立线索），遍历结束时需要恢复原结构。