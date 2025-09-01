// 哈希表法
func twoSum(nums []int, target int) []int {
    hashMap := make(map[int]int)
    for i, num := range nums {
        complement := target - num
        if index, exists := hashMap[complement]; exists {
            return []int{index, i}
        }
        hashMap[num] = i
    }
    return []int{}
}