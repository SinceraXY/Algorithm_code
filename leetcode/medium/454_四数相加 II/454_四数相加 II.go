func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
    umap := make(map[int]int) // key:a+b的数值，value:a+b数值出现的次数
    for _, a := range nums1 {
        for _, b := range nums2 {
            umap[a+b]++
        }
    }
    count := 0
    // 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
    for _, c := range nums3 {
        for _, d := range nums4 {
            count += umap[-c-d]
        }
    }
    return count
}