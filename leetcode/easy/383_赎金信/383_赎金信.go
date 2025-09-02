// 哈希
func canConstruct(ransomNote string, magazine string) bool {
    if len(ransomNote) > len(magazine) {
        return false
    }
    record := make([]int, 26)   //记录magazine里各个字符出现次数
    for _, char := range magazine {
        record[char-'a']++
    }
    for _, char := range ransomNote {
        record[char-'a']--
        if record[char-'a'] < 0 {    //如果小于零说明ransomNote里出现的字符，magazine里没有
            return false
        }
    }
    return true
}

// 时间复杂度: O(n)
// 空间复杂度：O(1)