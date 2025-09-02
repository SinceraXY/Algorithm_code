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