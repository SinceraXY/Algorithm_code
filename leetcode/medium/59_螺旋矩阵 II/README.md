# 59. 螺旋矩阵 II

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/spiral-matrix-ii/description/
- **难度**：Medium
- **标签**：数组、矩阵、模拟

## 题目描述

给你一个正整数 `n`，生成一个包含 `1` 到 `n²` 所有元素，且元素按顺时针顺序螺旋排列的 `n × n` 正方形矩阵。

**示例 1：**
```
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
```

**示例 2：**
```
输入：n = 1
输出：[[1]]
```

**提示：**
- `1 <= n <= 20`

## 解题思路

### 算法原理
使用**模拟**的方法，按照顺时针螺旋的方向依次填入数字：
1. **右** → **下** → **左** → **上** 的循环顺序
2. 维护四个边界：`up`（上边界）、`down`（下边界）、`left`（左边界）、`right`（右边界）
3. 每次填充完一个方向后，相应的边界收缩
4. 当所有数字填充完毕（`num > n²`）时结束

### 详细步骤
1. **向右填充**：从 `left` 到 `right`，填充 `up` 行，然后 `up++`
2. **向下填充**：从 `up` 到 `down`，填充 `right` 列，然后 `right--`
3. **向左填充**：从 `right` 到 `left`，填充 `down` 行，然后 `down--`
4. **向上填充**：从 `down` 到 `up`，填充 `left` 列，然后 `left++`

## 代码实现

### C++ 实现
```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        int up = 0, down = n-1, left = 0, right = n-1;
        
        while(num <= n*n) {
            // 从左到右填充上边
            for(int i = left; i <= right; i++) {
                res[up][i] = num++;
            }
            up++;
            
            // 从上到下填充右边
            for(int i = up; i <= down; i++) {
                res[i][right] = num++;
            }
            right--;
            
            // 从右到左填充下边
            for(int i = right; i >= left; i--) {
                res[down][i] = num++;
            }
            down--;
            
            // 从下到上填充左边
            for(int i = down; i >= up; i--) {
                res[i][left] = num++;
            }
            left++;
        }
        return res;
    }
};
```

### Python 实现
```python
class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        res = [[0] * n for _ in range(n)]
        num = 1
        up, down, left, right = 0, n-1, 0, n-1
        
        while num <= n * n:
            # 从左到右填充上边
            for i in range(left, right + 1):
                res[up][i] = num
                num += 1
            up += 1
            
            # 从上到下填充右边
            for i in range(up, down + 1):
                res[i][right] = num
                num += 1
            right -= 1
            
            # 从右到左填充下边
            for i in range(right, left - 1, -1):
                res[down][i] = num
                num += 1
            down -= 1
            
            # 从下到上填充左边
            for i in range(down, up - 1, -1):
                res[i][left] = num
                num += 1
            left += 1
        
        return res
```

### Go 实现
```go
func generateMatrix(n int) [][]int {
    res := make([][]int, n)
    for i := range res {
        res[i] = make([]int, n)
    }
    
    num := 1
    up, down, left, right := 0, n-1, 0, n-1
    
    for num <= n*n {
        // 从左到右填充上边
        for i := left; i <= right; i++ {
            res[up][i] = num
            num++
        }
        up++
        
        // 从上到下填充右边
        for i := up; i <= down; i++ {
            res[i][right] = num
            num++
        }
        right--
        
        // 从右到左填充下边
        for i := right; i >= left; i-- {
            res[down][i] = num
            num++
        }
        down--
        
        // 从下到上填充左边
        for i := down; i >= up; i-- {
            res[i][left] = num
            num++
        }
        left++
    }
    
    return res
}
```

## 复杂度分析

- **时间复杂度**：`O(n²)`
  - 需要填充 n×n 矩阵的每个位置，总共 n² 个元素
  - 每个元素只被访问一次

- **空间复杂度**：`O(1)`
  - 除了返回的结果矩阵外，只使用了常数级别的额外空间
  - 不计算返回值的空间复杂度为 O(1)

## 关键要点

1. **边界控制**：正确维护四个边界变量，确保不会越界
2. **方向切换**：按照固定的顺时针顺序进行方向切换
3. **终止条件**：当 `num > n²` 时停止填充
4. **边界收缩**：每完成一个方向的填充后，及时收缩对应边界

## 相关题目

- [54. 螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/) - 螺旋遍历矩阵
- [885. 螺旋矩阵 III](https://leetcode.cn/problems/spiral-matrix-iii/) - 螺旋矩阵变种