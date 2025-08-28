//哈希集合法
func intersection(nums1 []int, nums2 []int) []int {
    resultSet := make(map[int]bool)
    numsSet := make(map[int]bool)
    
    // 将nums1放入哈希集合
    for _, num := range nums1 {
        numsSet[num] = true
    }
    
    // 遍历nums2，查找交集
    for _, num := range nums2 {
        if numsSet[num] {
            resultSet[num] = true
        }
    }
    
    // 转换为切片返回
    result := make([]int, 0, len(resultSet))
    for num := range resultSet {
        result = append(result, num)
    }
    return result
}