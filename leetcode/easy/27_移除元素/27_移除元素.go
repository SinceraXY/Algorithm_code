//双指针法（快慢指针法）
func removeElement(nums []int, val int) int {
    slowIndex := 0
    for fastIndex := 0; fastIndex < len(nums); fastIndex++ {
        if nums[fastIndex] != val {
            nums[slowIndex] = nums[fastIndex]
            slowIndex++
        }
    }
    return slowIndex
}