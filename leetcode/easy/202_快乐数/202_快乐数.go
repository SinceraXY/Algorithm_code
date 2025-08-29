// 哈希表法
func getSum(n int) int {
    sum := 0
    for n > 0 {
        sum += (n % 10) * (n % 10)
        n /= 10
    }
    return sum
}

func isHappy(n int) bool {
    m := map[int]bool{}
    for ; n != 1 && !m[n]; n, m[n] = getSum(n), true { }
    return n == 1
}