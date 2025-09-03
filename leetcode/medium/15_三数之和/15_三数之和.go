// 双指针法
func threeSum(nums []int) [][]int {
    result := [][]int{}
    sort.Ints(nums)
    
    for i := 0; i < len(nums); i++ {
        // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
        if nums[i] > 0 {
            return result
        }
        
        // 正确去重方法
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        
        left := i + 1
        right := len(nums) - 1
        
        for right > left {
            if nums[i]+nums[left]+nums[right] > 0 {
                right--
            } else if nums[i]+nums[left]+nums[right] < 0 {
                left++
            } else {
                result = append(result, []int{nums[i], nums[left], nums[right]})
                // 去重逻辑应该放在找到一个三元组之后
                for right > left && nums[right] == nums[right-1] {
                    right--
                }
                for right > left && nums[left] == nums[left+1] {
                    left++
                }
                // 找到答案时，双指针同时收缩
                right--
                left++
            }
        }
    }
    
    return result
}