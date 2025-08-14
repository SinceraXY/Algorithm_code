//滑动窗口
func minSubArrayLen(target int, nums []int) int {
    result := int(^uint(0) >> 1) // 相当于 INT_MAX
    sum := 0
    length := 0
    i := 0
    for j := 0; j < len(nums); j++ {
        sum += nums[j]
        for sum >= target {
            length = j - i + 1
            if length < result {
                result = length
            }
            sum -= nums[i]
            i++
        }
    }
    if result == int(^uint(0) >> 1) {
        return 0
    }
    return result
}