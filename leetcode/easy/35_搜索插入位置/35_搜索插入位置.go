//二分法
func searchInsert(nums []int, target int) int {
    n := len(nums)
    left := 0
    right := n - 1
    for left <= right {
        middle := left + ((right - left) >> 1)
        if nums[middle] > target {
            right = middle - 1
        } else if nums[middle] < target {
            left = middle + 1
        } else {
            return middle
        }
    }
    return right + 1
}