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